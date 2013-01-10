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

	_steinNeu = new Stein(RandomStein(), _viewNeu);
}

Spiel::~Spiel()
{
	//Nothing to do here
}

void Spiel::Run()
{
	while(_runGame)
	{
		// Input all the time
		UInputs();
		// Render all the time
		Render();
		Update();
		Sleep(50);
	}
	//sstd::getchar();
}


// Spiele Logik hier
void Spiel::Update()
{
	if(_steinNeu->GetStatus())
	{
		if(!CheckForCollision())
			_steinNeu->Fallen();
	}
	else
	{
		_spielSteine.push_back(*_steinNeu);
		_steinNeu = new Stein(RandomStein(), _viewNeu);
	}
}


// Renderer um alles zu zeichnen
void Spiel::Render()
{		
	// Zeichne alles
	_viewNeu->ClearScreen();
	_steinNeu->Zeichne();
	
	for(_spielSteineIt = _spielSteine.begin(); _spielSteineIt != _spielSteine.end(); _spielSteineIt++)
	{
		_spielSteineIt->Zeichne();
	}
}

// Prueft auf Kollision returned true wenn kollidiert, false wenn nicht
bool Spiel::CheckForCollision()
{
	//aktuellerstein->Gety
	//vergleiche each vonliste mit aktuell
		//wenn y und 1 x gleich dann setze status falsch
	int y = _steinNeu->GetY();
	int x = _steinNeu->GetX();

	for(_spielSteineIt = _spielSteine.begin(); _spielSteineIt != _spielSteine.end(); _spielSteineIt++)
	{
		int yL = _spielSteineIt->GetY();
		int xL = _spielSteineIt->GetX();
		
		/*
		*	Gehe durch die Liste der bloecke eines steins und vergleiche die positionen von x und y
		*	Vergleiche ersten Block mit allen 4 ...
		*/
		for (_aktuellSteinIt = _steinNeu->_BlockList.begin(); _aktuellSteinIt != _steinNeu->_BlockList.end(); _aktuellSteinIt++)
		{
			// Hier block von dem nun genutzen spielstein durchgehen 
			for()
			{
				int xFall = _aktuellSteinIt->GetXPos();
				int yFall = _aktuellSteinIt->GetYPos();

				if(xFall == xL && yFall+2 == yL)
				{
					_steinNeu->SetStatus(false);
					return true;
				}
			}
		}

		if(y+2 == yL && x == xL)
		{
			_steinNeu->SetStatus(false);
			return true;
		}

	}
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
				//_steinNeu->Bewegen(3);
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


int Spiel::RandomStein()
{
	int typrandom;
	srand(static_cast<unsigned>(time(0)));
	typrandom = rand() & 7;
	return typrandom;
}