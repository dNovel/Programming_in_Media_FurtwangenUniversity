/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "SteinTetr.h"


// Konstruktor hier wos ist
Stein::Stein(int status, int farbe, View *view)
{
	_Status = status;
	_Farbe = farbe;
	//_FormTyp = formtyp;
	//_view = view;

	// @TODO:
	Block *block1 = new Block(10, 0);
	Block *block2 = new Block(11, 0);
	Block *block3 = new Block(10, 1);
	Block *block4 = new Block(11, 1);

	_BlockList.push_back(*block1);
	_BlockList.push_back(*block2);
	_BlockList.push_back(*block3);
	_BlockList.push_back(*block4);
}

Stein::~Stein()
{
	
}

void Stein::Bewegen()
{

}

void Stein::Drehen()
{

}

void Stein::Fallen()
{
	std::list<Block>::iterator listIterator;
	
	for(listIterator = _BlockList.begin(); listIterator != _BlockList.end(); listIterator++)
	{
		listIterator->Fallen();
	}
}

void Stein::Zeichne()
{
	// Rufe Zeichne von Block auf, der sich dann im view zeichnet
	std::list<Block>::iterator listIterator;
	
	for(listIterator = _BlockList.begin(); listIterator != _BlockList.end(); listIterator++)
	{
		listIterator->Zeichne(this->_view);
	}
}