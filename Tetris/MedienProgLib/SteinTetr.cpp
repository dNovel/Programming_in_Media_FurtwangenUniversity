/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "SteinTetr.h"


// Konstruktor hier wos ist
Stein::Stein(int status, View *view)
{
	_Status = true;
	_view = view;

	_x = 10;
	_y = 0;

	_BlockList.push_back(Block(10, 0));
	_BlockList.push_back(Block(11, 0));
	_BlockList.push_back(Block(10, 1));
	_BlockList.push_back(Block(11, 1));

	/*
	//TODO Hier nach Typ pruefen und dann erstellen
	Block *block1 = new Block(10, 0);
	Block *block2 = new Block(11, 0);
	Block *block3 = new Block(10, 1);
	Block *block4 = new Block(11, 1);

	_BlockList.push_back(*block1);
	_BlockList.push_back(*block2);
	_BlockList.push_back(*block3);
	_BlockList.push_back(*block4);
	*/
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
	/*
	for(listIterator = _BlockList.begin(); listIterator != _BlockList.end(); listIterator++)
	{
		// Drehe Stein um 90grad im uzs
		int newX = listIterator->GetYPos();
		int newY = (listIterator->GetXPos() * -1);
		// Vorherig - neu = diff ... dann diff + aktuell
	}
	*/
}

void Stein::Fallen()
{
	int hPos = (_view->GetHeight()-1);
	if(_y >= hPos)
	{
		_Status = false;
	}
	

	if(_Status && _y < hPos)
	{
		for(_blockListIt = _BlockList.begin(); _blockListIt != _BlockList.end(); _blockListIt++)
		{
			_blockListIt->Fallen();
		}
		_y += 1;
	}
}

void Stein::Zeichne()
{
	
	for(_blockListIt = _BlockList.begin(); _blockListIt != _BlockList.end(); _blockListIt++)
	{
		_blockListIt->Zeichne(this->_view);
	}
}

bool Stein::GetStatus()
{
	return _Status;
}

void Stein::SetStatus(bool val)
{
	_Status = val;
}