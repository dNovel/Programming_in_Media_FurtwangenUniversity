/*
	Medienprogrammierung - Dominik Steffen 2012
*/

class View
{
public:
	View();
	View(int hoehe, int breite);
	~View();
private:
	int	_Hoehe;
	int _Breite;

	void Zeichne(int x, int y);
	void GoToPos(int x, int y);
	void GoToPosZero();
	void Set_console(int height, int width);
	void ClearScreen();
};