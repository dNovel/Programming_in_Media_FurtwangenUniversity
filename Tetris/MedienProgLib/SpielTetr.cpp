/*
 *	Test Programm fuer den Desktop
 */
#include <stdio.h>
#include <conio.h>
#include "SpielTetr.h"


Spiel::Spiel()
{
	_runGame = true;
	_viewNeu = new View(40, 30); // h und b
	_steinNeu = new Stein(0, _viewNeu);
}

Spiel::~Spiel()
{
	//Nothing to do here
}

void Spiel::Run()
{
	// Hole die aktuelle Zeit seit ... in ms
	long lastTime = GetClockMSTime();
	long lastTimer = GetClockMSTime();
	double msPerTick =  1000 / 60.0;

	double delta = 0;
	int frames = 0;
	int updates = 0;

	while(_runGame)
	{
		long now = GetClockMSTime();
		delta += (now - lastTime) / msPerTick;
		lastTime = now;

		// Input all the time
		UInputs();

		while (delta >= 1)
		{
			updates++;
			delta-=1;
		}
		// Render all the time
		Render();
		frames++;
		
		long timeUp = GetClockMSTime() - lastTimer;
		if(timeUp > 1000)
		{
			lastTimer += 1000;
			
			// Spiele Logik
			Update();

			frames = 0;
			updates = 0;
		}
	}
	std::getchar();
}


// Spiele Logik hier
void Spiel::Update()
{
	if(_steinNeu->GetStatus())
	{
		_steinNeu->Fallen();
	}
	else
	{
		_spielSteine.push_back(*_steinNeu);
		_steinNeu = new Stein(0, _viewNeu);
	}
}


// Renderer um alles zu zeichnen
void Spiel::Render()
{		
	// Zeichne alles
	_steinNeu->Zeichne();
	for(_spielSteineIt = _spielSteine.begin(); _spielSteineIt != _spielSteine.end(); _spielSteineIt++)
	{
		_spielSteineIt->Zeichne();
	}

	_viewNeu->ClearScreen();
}

long Spiel::GetClockNanoTime()
{
	return time(NULL) * 1000000000;
}

long Spiel::GetClockMSTime()
{
	return time(NULL) * 1000;
}

// Prueft auf Kollision returned true wenn kollidiert, false wenn nicht
bool Spiel::CheckForCollision()
{
	return false;
}


void Spiel::UInputs()
{
	// Tastatur abfragen
	int keyIn = Spiel::GetKeyboardInput();
	if(keyIn != 0) // Es wurde eine Taste gedrückt
	{
		switch(keyIn)
		{
		case 27: // [ESC]
			//endGame();
			break;
		case 32:
			// Stein drehen ...
			_steinNeu->Drehen();
			break;
		case 224: // Special key
			int keyIn2= Spiel::GetKeyboardInput(); // Wenn es eine Spezialtaste ist, den zweiten Code holen
			switch(keyIn2)
			{
			case 75: // [<-]
				// Stein bewegen...
				_steinNeu->Bewegen(1);
				break;
			case 77: // [->]
				// Stein bewegen...
				_steinNeu->Bewegen(2);
				break;
			case 80: // [ v ]
				// Stein bewegen...
				_steinNeu->Bewegen(3);
				break;
			}
			break;
		}
	}
}

// Hole den Input von der Tastatur
int Spiel::GetKeyboardInput()
{
	 fflush(stdin);
	 int returnVal = 0;
	 if(kbhit() != 0)
	 {
		returnVal=getch();
		if(returnVal==0)
			returnVal=256+getch();
	}
	return returnVal;
}