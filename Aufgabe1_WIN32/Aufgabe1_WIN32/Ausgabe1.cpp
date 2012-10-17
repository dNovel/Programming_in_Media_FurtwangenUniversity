#include <stdio.h>
#include "Aufgabe1.h";

int _Hoehe;
int _Breite;
int _RauteBreite;
char _Buchstabe;

int main()
{
	//// Teil 1
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

	AusgabeRaute(_RauteBreite, _Buchstabe);

	return 0;
}


void AusgabeViereck(int breite, int hoehe, char buchstabe)
{
	for(int i=0; i<hoehe; i++)
	{
		for(int j=0; j<breite; j++)
		{
			printf("%c", buchstabe);
		}
		printf("\n");
	}
}

void AusgabeRaute(int anzahl, char buchstabe)
{
	int anzahl1 = (anzahl/2) + 1;
	int laenge = (anzahl*2) - 1;

	for (int i=0; i<anzahl1; i++)
	{
		for (int j = 0 ; j < laenge; j++)
		{
			if ( (j > (laenge/2) - i) && (j < (laenge/2) + i) )
			{
				printf("%c", buchstabe);
			}
			else
			{
				printf(" ");
			}
		}
	  printf("\n");
	 }

	 for(int i = anzahl - anzahl1+1; i > 0 ; i--)
	 {
		for(int j = laenge; j > 0 ; j--)
		{
			if( (j > (anzahl-1 / 2) - i) && (j < (anzahl-1 / 2) + i) )
			{
				printf("%c", buchstabe);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	 }
}