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

void Stein::Bewegen(int mDirection)
{
	int moveMult = 1;

	switch(mDirection)
	{
	case 1:
		// bewege links
		moveMult = -1;
		break;
	case 2:
		// bewege rechts
		moveMult = 1;
		break;
	case 3:
		// bewege nach unten
		moveMult = 0;
		break;
	}

	// Iteriere ueber die Steine und verschiebe sie
	std::list<Block>::iterator listIterator;
	for(listIterator = _BlockList.begin(); listIterator != _BlockList.end(); listIterator++)
	{
		if(moveMult == 0)
		{
			int y = listIterator->GetYPos();
			y = y + 1;
			listIterator->SetYPos(y);
		}
		else
		{
			int x = listIterator->GetXPos();
			int amount = 1 * moveMult;
			x = x + amount;
			listIterator->SetXPos(x);
		}
	}

}

void Stein::Drehen()
{
	std::list<Block>::iterator listIterator;
	
	for(listIterator = _BlockList.begin(); listIterator != _BlockList.end(); listIterator++)
	{
		// Drehe Stein um 90grad im uzs
		int newX = listIterator->GetYPos();
		int newY = (listIterator->GetXPos() * -1);

		// Vorherig - neu = diff ... dann diff + aktuell

	}
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