// Tetris Spiel Datei
// Benutzt die Library um ein Spiel zu erzeugen
// Enthält keinerlei Spiel Funktion
#include "SpielTetr.h";

int main()
{
	
	Spiel *tetrisSpiel = new Spiel();
	tetrisSpiel->Run();
	
	return 0;
}