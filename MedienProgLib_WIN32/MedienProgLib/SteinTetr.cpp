/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include "SteinTetr.h"


// Konstruktor hier wos ist
Stein::Stein(int status, int farbe, View *view)
{
	_Status = true;
	_Farbe = farbe;
	//_FormTyp = formtyp;
	//_view = view;
	_x = 10;
	_y = 0;

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
	if(_Status)
	{
		std::list<Block>::iterator blockList;
		for(blockList = _BlockList.begin(); blockList != _BlockList.end(); blockList++)
		{
			int yPos = blockList->GetYPos();
			//FIXME Stein faellt ineinander weil die oberen nachruecken
			if(yPos < 20)
			{
				//_y += 1; // only debug
				if(_Status)
				{
					blockList->Fallen();
				}
				else
				{
				}
			}
			else
			{
				_Status = false;
				//break;
				return;
			}
		}
	}
}

// Prueft auf Kollision returned true wenn kollidiert false wenn nicht
bool Stein::CheckStoneForCollision(Stein *fallingStone)
{
	std::list<Block> outBlockList;
	fallingStone->GetBlockList(outBlockList);

	// prepare
	int fallingblockY[4];
	int fallingblockX[4];
	int standingblockX[4];
	int standingblockY[4];
	int i = 0;
	int j = 0;
	// iteriere ueber die bloecke und teste die koordinaten
	std::list<Block>::iterator listIterator;	
	for(listIterator = outBlockList.begin(); listIterator != outBlockList.end(); listIterator++)
	{
		fallingblockX[i] = listIterator->GetXPos();
		fallingblockY[i] = listIterator->GetYPos();
		i++;
	}

	for(listIterator = _BlockList.begin(); listIterator != _BlockList.end(); listIterator++)
	{
		standingblockX[j] = listIterator->GetXPos();
		standingblockY[j] = listIterator->GetYPos();
	}

	//bool hit=false;
	for(int k=0; k<4; k++)
	{
		if(fallingblockY[k]+1 == standingblockY[k] && fallingblockX[k] == standingblockX[k])
		{
			return true;
			//bool hit = true;
			//break;
		}
	}
	return false;
}

void Stein::GetBlockList(std::list<Block> &outList)
{
	outList = _BlockList;
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

bool Stein::GetStatus()
{
	return _Status;
}