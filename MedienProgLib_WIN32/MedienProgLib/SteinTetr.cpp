/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "SteinTetr.h"


// Konstruktor
Stein::Stein(int status, int farbe, int formtyp)
{
	Stein::_Status = status;
	Stein::_Farbe = farbe;
	Stein::_FormTyp = formtyp;
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