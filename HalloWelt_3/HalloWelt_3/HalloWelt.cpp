//	Drittes HalloWelt Programm im WS2012/2013

// Eigene Includes
#include "HalloWelt.h";
#include "Ausgabe.h";

void main(void)
{
	int anzahl = 10;

	// New Objekt auf dem Heap mit dem Pointer '*' anlegen
	Ausgabe *ausGb1 = new Ausgabe(anzahl);
	// Auf das Objekt zugreifen
	ausGb1->HalloWeltAusgabe();
}