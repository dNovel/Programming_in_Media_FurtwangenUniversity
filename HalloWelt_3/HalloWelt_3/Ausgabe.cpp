// Standard Header
#include <stdio.h>;
// Eigene Includes
#include "Ausgabe.h";

int anzahl;

Ausgabe::Ausgabe(int anzahlInc)
{
	anzahl = anzahlInc;
}

void Ausgabe::HalloWeltAusgabe()
{
	for(int i=0; i<this->anzahl; i++)
	{
		printf("Hallo schoene Welt im Regen!\n");
	}
}