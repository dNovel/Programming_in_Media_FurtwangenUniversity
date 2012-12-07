/*
 *	Test Programm fuer den Desktop
 */
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "SpielTetr.h"


Spiel::Spiel()
{
	FRAMES_PER_SECOND = 60;
	SKIP_TICKS = 1000 / FRAMES_PER_SECOND;

	_viewNeu = new View(40, 30);
	_steinNeu = new Stein(0, 0, _viewNeu);
}

Spiel::~Spiel()
{
	//Nothing to do here
}

void Spiel::Run()
{
	bool run = true;
	while(run)
	{
		if(_steinNeu->_Status)
		{
			// Steuerung
			Update();

			//TODO Frage nach Kollision ab
			/*
			bool istEs = CheckForCollision();
			if(istEs)
			{
				// Werde nicht bewegbar
				_steinNeu->_Status = false;
			}
			else
			{
				// Falle weiter weil nicht kollidiert
				_steinNeu->Fallen();
			}*/
			_steinNeu->Fallen();
		}
		else
		{
			// Haenge um mach neuen Stein
			_spielSteine.push_back(*_steinNeu);
			//_steinNeu = new Stein(0, 0, _viewNeu);
		}
		Render();
	}

	// Warte auf Enter um das Programm zu beenden und zeige keinen Text an
	std:getchar();
	//return 0;
}

// Renderer um alles zu zeichnen
void Spiel::Render()
	{		
		next_game_tick += 1;
		if(next_game_tick >= SKIP_TICKS)
		{
			_viewNeu->ClearScreen();
			_steinNeu->Zeichne();

			for(_steinlisteIt = _spielSteine.begin(); _steinlisteIt != _spielSteine.end(); _steinlisteIt++)
			{
				_steinlisteIt->Zeichne();
			}
		}
	}

// Prueft auf Kollision returned true wenn kollidiert, false wenn nicht
bool Spiel::CheckForCollision()
{
	for(_steinlisteIt = _spielSteine.begin(); _steinlisteIt != _spielSteine.end(); _steinlisteIt++)
	{
		bool isIt = _steinlisteIt->CheckStoneForCollision(_steinNeu);
		if(isIt)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Spiel::Update()
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