#include <stdio.h>
#include "Aufgabe1.h";
#include "MPLSammlung.h"

int _Hoehe;
int _Breite;
int _RauteBreite;
char _Buchstabe;

int main()
{
	// Teil 1
	//printf("Bitte Breite des Vierecks angeben: ");
	//scanf("%d", &_Breite);
    
	//printf("Bitte Hoehe des Vierecks angeben: ");
	//scanf("%d", &_Hoehe);
    
	//printf("Bitte den Buchstaben der ausgegeben werden soll eingeben: ");
	//scanf(" %c", &_Buchstabe);
    
	//AusgabeViereck(_Breite, _Hoehe, _Buchstabe);
    
	// Teil 2
	do
	{
		printf("Bitte eine UNGERADE maximale Anzahl pro Zeile in der Raute angeben: ");
		scanf("%d", &_RauteBreite);
	}
	while((_RauteBreite%2)==0);
	
	printf("Bitte den Buchstaben der ausgegeben werden soll eingeben: ");
	scanf(" %c", &_Buchstabe);
    
    AusgabeRaute(_RauteBreite, _Buchstabe, 10, 8);

	return 0;
}