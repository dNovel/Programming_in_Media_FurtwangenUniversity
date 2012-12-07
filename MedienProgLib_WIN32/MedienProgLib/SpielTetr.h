/*
	Medienprogrammierung - Dominik Steffen 2012
*/
#include <list>
#include "SteinTetr.h"
#include "ViewTetr.h"

class Spiel
{
private:
	void Update();
	int GetKeyboardInput();
	void Render();
	bool CheckForCollision();

	// Renderer
	double long pastTime;
	double long tps;
	double long nowTime;
	int FRAMES_PER_SECOND;
	int SKIP_TICKS;
	DWORD next_game_tick;
	int sleep_time;
	std::list<Stein>::iterator _steinlisteIt;

	Stein *_steinNeu;
	std::list<Stein> _spielSteine;
public:
	Spiel();
	~Spiel();
	void Run();

	View *_viewNeu;
};