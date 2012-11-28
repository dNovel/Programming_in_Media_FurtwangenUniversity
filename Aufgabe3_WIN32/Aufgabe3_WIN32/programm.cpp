/*
 *	Test Programm fuer den Desktop
 */
#include <stdio.h>
#include <time.h>
#include "ViewTetr.h"
#include <conio.h>
#include "programm.h"

int main()
{
	View *viewNeu = new View(40, 40);
	Stein *steinNeu = new Stein(0, 0, viewNeu);

	bool out = false;
	int i = 0;
	while(!out)
	{
		// Steuerung
		update(steinNeu);

		steinNeu->Fallen();
		viewNeu->ClearScreen();
		steinNeu->Zeichne();
		Sleep(100);

		//if(block->GetYPos() > 39)
		//	out = true;
	}

	// Warte auf Enter um das Programm zu beenden und zeige keinen Text an
	std:getchar();
	return 0;
}


void update(Stein *stein)
{
	// Tastatur abfragen
	int keyIn = getKeyboardInput();
	if(keyIn != 0) // Es wurde eine Taste gedrückt
	{
		switch(keyIn)
		{
		case 27: // [ESC]
			//endGame();
			break;
		case 32:
			// Stein drehen ...
			stein->Drehen();
			break;
		case 224: // Special key
			int keyIn2= getKeyboardInput(); // Wenn es eine Spezialtaste ist, den zweiten Code holen
			switch(keyIn2)
			{
			case 75: // [<-]
				// Stein bewegen...
				stein->Bewegen(1);
				break;
			case 77: // [->]
				// Stein bewegen...
				stein->Bewegen(2);
				break;
			case 80: // [ v ]
				// Stein bewegen...
				stein->Bewegen(3);
				break;
			}
			break;
		}
	}
}


// Hole den Input von der Tastatur
int getKeyboardInput()
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