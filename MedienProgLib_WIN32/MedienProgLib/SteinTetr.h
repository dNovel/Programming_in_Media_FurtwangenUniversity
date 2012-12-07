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
	bool _Status; // 0 ist bewegbar 1 ist fest
	int _Farbe;
	int _FormTyp; // Geometrische Form des Steins
	int _x, _y;

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
	// Bewegt den Stein durch Benutzereingabe
	void Bewegen(int mDirection);
	// Dreht den Stein durch Benutzereingabe
	void Drehen();
	bool GetStatus();

	// pruefe kollision
	bool CheckStoneForCollision(Stein *fallingStone);
	void GetBlockList(std::list<Block> &outList);
private:
	// Kolission mit unterem Stein? @TODO:
	void Crash();
	// Destruktor Methode
	void Clear();
};
#endif