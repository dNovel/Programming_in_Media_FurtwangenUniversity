/*
	Medienprogrammierung - Dominik Steffen 2012
*/

#ifndef __BlockTetr_H__
#define __BlockTetr_H__

#include "ViewTetr.h"

class Block
{
public:
	Block();
	Block(int x, int y);
	~Block();

	// Getter
	int GetXPos();
	int GetYPos();
	char GetChar();

	// Setter
	void SetXPos(int);
	void SetYPos(int);
	void SetChar(char val);
	void Zeichne(View *view);
	void Fallen();

private:
	int _x;
	int _y;
	char _asciichar;
};
#endif