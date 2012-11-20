/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "ViewTetr.h"

// Konstruktor
View::View(int hoehe, int breite)
{
	this->_Hoehe = hoehe;
	this->_Breite = breite;

	View::Set_console(_Hoehe, _Breite);
}

void View::Zeichne(int x, int y, char c)
{
	this->GoToPos(x, y);
	printf("%c", c);
}

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