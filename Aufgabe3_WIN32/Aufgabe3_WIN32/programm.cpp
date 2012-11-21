/*
 *	Test Programm fuer den Desktop
 */
#include <stdio.h>
#include <time.h>
#include "ViewTetr.h"
#include "SteinTetr.h"

int main()
{
	View *viewNeu = new View(40, 20);
	Stein *steinNeu = new Stein(0, 0, viewNeu);

	bool out = false;
	int i = 0;
	while(!out)
	{
		steinNeu->Fallen();
		viewNeu->ClearScreen();
		steinNeu->Zeichne();
		Sleep(100);

		//if(block->GetYPos() > 39)
		//	out = true;
		i++;
		if(i>=39)
			out = true;
	}

	// Warte auf Enter um das Programm zu beenden und zeige keinen Text an
	std:getchar();
	return 0;
}