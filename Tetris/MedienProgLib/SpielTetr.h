/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include <list>
#include <time.h>
#include <sys\timeb.h>
#include "SteinTetr.h"
#include "ViewTetr.h"


class Spiel
{
private:
	void Update();
	void UInputs();
	void Render();
	int GetKeyboardInput();
	bool CheckForCollision();
	long GetClockNanoTime();
	long GetClockMSTime();
	int RandomStein();

	std::list<Stein> _spielSteine;
	std::list<Stein>::iterator _spielSteineIt;
	std::list<Block>::iterator _aktuellSteinIt;
	Stein *_steinNeu;

	bool _runGame;

	double long pastTime;
	double long tps;
	double long nowTime;	
	
public:
	Spiel();
	~Spiel();
	void Run();

	View *_viewNeu;
};