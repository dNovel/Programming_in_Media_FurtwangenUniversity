/*
	Medienprogrammierung - Dominik Steffen 2012
*/
//#ifndef __SteinTetr_H__
//#define __SteinTetr_H__
#ifdef __SteinTetr_H__
class Stein;
#else
#define __SteinTetr_H__

#include <list>
#include "BlockTetr.h"
#include "ViewTetr.h"

class Stein
{
public:
	int _Status; // 0 ist bewegbar 1 ist fest
	int _Farbe;
	int _FormTyp; // Geometrische Form des Steins
	//View
	View *_view;
	// Liste mit Steinen
	std::list<Block> _BlockList;
	// Konstruktor
	Stein();
	Stein(int status, int farbe, View *view);
	~Stein();
	// Zeichnet den Stein auf den View - delegate methode
	void Zeichne();
	// Laesst den Stein fallen
	void Fallen();
private:
	// Dreht den Stein durch Benutzereingabe
	void Drehen();
	// Bewegt den Stein durch Benutzereingabe
	void Bewegen();
	// Kolission mit unterem Stein? @TODO:
	void Crash();
	// Destruktor Methode
	void Clear();
};
#endif