/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "SteinTetr.h"


// Konstruktor hier wos ist
Stein::Stein(int typ, View *view)
{
	_Status = true;
	_view = view;

	_x = 10;
	_y = 0;

	int ax,ay,bx,by,cx,cy,dx,dy;

	switch(typ)
	{
		case 0: 
		ax = 5;
		ay = 1;
		bx = 6;
		by = 1;
		cx = 5;
		cy = 2;
		dx = 6;
		dy = 2;
		break;
		case 1: 
		//TStueck
		ax = 5;
		ay = 1;
		bx = 6;
		by = 1;
		cx = 7;
		cy = 1;
		dx = 6;
		dy = 2;
		break;
		case 2: 
		//LForm
		ax = 5;
		ay = 1;
		bx = 6;
		by = 1;
		cx = 7;
		cy = 1;
		dx = 7;
		dy = 2;
		break;
		case 3: 
		//LFormGespiegelt
		ax = 5;
		ay = 2;
		bx = 5;
		by = 1;
		cx = 6;
		cy = 1;
		dx = 7;
		dy = 1;
		break;
		case 4: 
		//Viererblock
		ax = 5;
		ay = 1;
		bx = 6;
		by = 1;
		cx = 5;
		cy = 2;
		dx = 6;
		dy = 2;
		break;
		case 5: 
		//Z
		ax = 5;
		ay = 1;
		bx = 6;
		by = 1;
		cx = 6;
		cy = 2;
		dx = 7;
		dy = 2;
		break;
		case 6: 
		//ZGespiegelt
		ax = 5;
		ay = 2;
		bx = 6;
		by = 2;
		cx = 6;
		cy = 1;
		dx = 7;
		dy = 1;
		break;
		default: 
		//ZGespiegelt
		ax = 5;
		ay = 2;
		bx = 6;
		by = 2;
		cx = 6;
		cy = 1;
		dx = 7;
		dy = 1;
		break;
	}

	Block *block1 = new Block(ax,ay);
	Block *block2 = new Block(bx,by);
	Block *block3 = new Block(cx,cy);
	Block *block4 = new Block(dx,dy);
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
		this->_x--;
		break;
	case 2:
		// bewege rechts
		moveMult = 1;
		this->_x++;
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
	// Hier pruefen ob unter dem Stein Platz ist
	// Liste durchgehen und sehen ob an der aktuellen coordinate drunter was liegt?

	int hPos = (_view->GetHeight()-2);
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


int Stein::GetY()
{
	return this->_y;
}


int Stein::GetX()
{
	return this->_x;
}