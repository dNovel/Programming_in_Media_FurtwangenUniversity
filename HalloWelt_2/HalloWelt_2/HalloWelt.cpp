// Zweites HalloWelt Programm im WS2012/2013

// Standard Header
#include <stdio.h>;

// Eigene Header
#include "HalloWelt.h";

void main(void)
{
	int ausgabeAnzahl = 3;
	HalloWeltAusgabe(ausgabeAnzahl);
}

void HalloWeltAusgabe(int anzahl)
{
	for(int i=0; i<anzahl; i++)
	{
		printf("Hallo schoene Welt im Regen!\n");
	}
}