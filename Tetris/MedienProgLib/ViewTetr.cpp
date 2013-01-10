/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "ViewTetr.h"

// Konstruktor
View::View(int hoehe, int breite)
{
	//_Hoehe = hoehe;
	//_Breite = breite;

	View::Set_console(_Hoehe, _Breite);

	/*
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(TEXT("Tetris! Pre-Alpha"));
	SMALL_RECT consoleSize = {0,0, _Breite, _Hoehe};
	SetConsoleWindowInfo(hConsoleOutput, TRUE, &consoleSize);
	*/
}

void View::Zeichne(int x, int y, char c)
{
	this->GoToPos(x, y);
	printf("%c", c);
	// Fuer WriteConsoleOutputA
	//ClearDrawBuffer();

	//FIXME wird fuer jeden block aufgerufen sollte aber pro stein gerufen werden
	/*
	lpBuffer[x + _Breite * y].Char.AsciiChar = 178;
	lpBuffer[x + _Breite * y].Attributes = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; //TODO dynamisch

	COORD dwBufferSize = {_Breite, _Hoehe};
	COORD dwBufferCoord = {0, 0};
	SMALL_RECT lpWriteRegion = {0, 0, _Breite-1, _Hoehe-1};

	WriteConsoleOutputA( hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, &lpWriteRegion);
	*/
}

/*
void View::ClearDrawBuffer()
{
	for(int x = 0; x < _Breite; x++)
	{
		for(int y = 0; y < _Hoehe; y++)
		{
			lpBuffer[x + _Breite * y].Char.AsciiChar = ' ';
			lpBuffer[x + _Breite * y].Attributes = 0;
		}
	}
}
*/

void View::Set_console(int height, int width)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT size;
	COORD b_size;

	size.Left = 0;
	size.Top = 0;
	size.Right = width;
	size.Bottom = height;
	b_size.X = width+1; //breite+1
	b_size.Y = height+1; //höhe+1

	SetConsoleWindowInfo(hCon, true, &size);
	SetConsoleScreenBufferSize(hCon, b_size);

	View::ClearScreen();
}


void View::GoToPos(int x, int y)
{
	COORD cur={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
}


void View::GoToPosZero()
{
	COORD cur={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
}

void View::ClearScreen()
{
	system("cls");
}

int View::GetHeight()
{
	return _Hoehe;
}