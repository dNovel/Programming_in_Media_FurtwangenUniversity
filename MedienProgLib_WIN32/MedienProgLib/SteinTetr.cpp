/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "SteinTetr.h"


/*
	Vars
*/
int _Status; // 0 ist bewegbar 1 ist fest
int _Farbe;
int _FormTyp; // Geometrische Form des Steins


// Konstruktor
Stein::Stein()
{
}

Stein::Stein(int status, int farbe, int formtyp)
{
	_Status = status;
	_Farbe = farbe;
	_FormTyp = formtyp;
}

Stein::~Stein()
{
	Clear();
}

void Stein::Bewegen()
{

}

void Stein::Drehen()
{

}

void Stein::Fallen()
{

}

void Stein::Zeichne()
{
	// Rufe Zeichne von Block auf, der sich dann im view zeichnet
}