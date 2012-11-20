/*
 *	Test Programm fuer den Desktop
 */

#include <stdio.h>
#include <time.h>
#include "BlockTetr.h"
#include "ViewTetr.h"

int main()
{
	View *view = new View(40, 20);
	Block *block = new Block(10, 0);

	bool out = false;
	while(!out)
	{
		block->Fallen();
		view->ClearScreen();
		block->Zeichne(view);
		Sleep(100);

		if(block->GetYPos() > 39)
			out = true;
	}

	return 0;
}