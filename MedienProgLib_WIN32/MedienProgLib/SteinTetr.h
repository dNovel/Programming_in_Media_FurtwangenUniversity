/*
	Medienprogrammierung - Dominik Steffen 2012
*/
class Stein
{
public:
	int _Status; // 0 ist bewegbar 1 ist fest
	int _Farbe;
	int _FormTyp; // Geometrische Form des Steins

	// Konstruktor
	Stein();
	Stein(int status, int farbe, int formtyp);
	~Stein();
private:
	// Dreht den Stein durch Benutzereingabe
	void Drehen();
	// Bewegt den Stein durch Benutzereingabe
	void Bewegen();
	// Zeichnet den Stein auf den View - delegate methode
	void Zeichne();
	// Laesst den Stein fallen
	void Fallen();
	// Kolission mit unterem Stein? @TODO:
	void Crash();
	// Destruktor Methode
	void Clear();
};