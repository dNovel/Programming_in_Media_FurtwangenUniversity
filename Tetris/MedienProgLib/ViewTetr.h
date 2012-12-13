/*
	Medienprogrammierung - Dominik Steffen 2012
*/

#ifdef __ViewTetr_H__
class View;
#else
#define __ViewTetr_H__

#include <stdio.h>
#include <Windows.h>

class View
{

public:
	View();
	View(int hoehe, int breite);
	~View();
	void Zeichne(int, int, char);
	void ClearScreen();
	int GetHeight();

private:
	int	_Hoehe;
	int _Breite;
	int _ITEMARRAYSIZE;

	void GoToPos(int x, int y);
	void GoToPosZero();
	void Set_console(int height, int width);
};
#endif