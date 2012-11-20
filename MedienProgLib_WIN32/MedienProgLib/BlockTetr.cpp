/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "BlockTetr.h"

Block::Block(){}

Block::Block(int x, int y)
{
	SetXPos(x);
	SetYPos(y);
	SetChar((char)254);
}

void Block::Zeichne(View *view)
{
	int x = GetXPos();
	int y = GetYPos();
	char c = GetChar();
	view->Zeichne(x, y, c);
}

void Block::Fallen()
{
	int newY = GetYPos();
	++newY;
	SetYPos(newY);
}

int Block::GetXPos()
{
	return _x;
}

int Block::GetYPos()
{
	return _y;
}

char Block::GetChar()
{
	return _asciichar;
}

void Block::SetXPos(int val)
{
	_x = val;
}

void Block::SetYPos(int val)
{
	_y = val;
}

void Block::SetChar(char val)
{
	_asciichar = val;
}