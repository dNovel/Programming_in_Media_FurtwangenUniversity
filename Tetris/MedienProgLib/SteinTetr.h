/*
	Medienprogrammierung - Dominik Steffen 2012
*/
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
	Stein();
	Stein(int status, View *view);
	~Stein();

	bool _Status;
	int _FormTyp;
	int _x, _y;
	View *_view;
	std::list<Block> _BlockList;
	std::list<Block>::iterator _blockListIt;

	void Zeichne();
	void Fallen();
	void Bewegen(int mDirection);
	void Drehen();
	bool GetStatus();
	void SetStatus(bool val);
};
#endif