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
	void ClearDrawBuffer();
	int GetHeight();

private:
	//int	_Hoehe;
	//int _Breite;
	static const int _Hoehe = 40;
	static const int _Breite = 30;
	int _ITEMARRAYSIZE;

	//HANDLE hConsoleOutput;
	//CHAR_INFO lpBuffer[_Breite * _Hoehe];

	void GoToPos(int x, int y);
	void GoToPosZero();
	void Set_console(int height, int width);
};
#endif