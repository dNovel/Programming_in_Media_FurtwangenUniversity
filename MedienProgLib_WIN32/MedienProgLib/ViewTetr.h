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
	void Zeichne();
	static char Spielfeld[20][10];
}