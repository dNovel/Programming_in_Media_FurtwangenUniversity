/*
	Medienprogrammierung - Dominik Steffen 2012
*/

#include <stdio.h>
#include "ViewTetr.h"

/*
	Vars
*/
int	_Hoehe;
int _Breite;

// Konstruktor
View::View()
{
}

View::View(int hoehe, int breite)
{
	_Hoehe = hoehe;
	_Breite = breite;
}

View::~View()
{
}

void View::Zeichne()
{
	// Traversiere Array und gib es aus
}