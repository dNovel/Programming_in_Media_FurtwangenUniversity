/*
	Medienprogrammierung - Dominik Steffen 2012
*/

#ifdef __BlockTetr_H__
class Block;
#else
#define __BlockTetr_H__
#include "ViewTetr.h"

class Block
{
public:
	Block();
	Block(int x, int y);
	~Block();

	int GetXPos();
	int GetYPos();
	char GetChar();

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