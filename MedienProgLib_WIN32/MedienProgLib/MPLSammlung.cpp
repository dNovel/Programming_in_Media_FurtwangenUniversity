#include <stdio.h>
#include <Windows.h>
#include "MPLSammlung.h"

// Groesse des 'grafischen Arrays'
const int _ITEMARRAYSIZE = 32;

void f1()
{
	printf("Ausgabe von f1! \n");
}

void GoToPos(int x, int y)
{
	COORD cur={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
}

void GoToPosZero()
{
	COORD cur={0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
}

// Gibt ein beliebiges Viereck auf der Konsole aus
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

// Gibt eine beliebige Raute auf der Konsole aus
void AusgabeRaute(int anzahl, char buchstabe, int sx,  int sy)
{
	char printArr[_ITEMARRAYSIZE][_ITEMARRAYSIZE] = {};

    for(int i=1; i<=anzahl; i++)
    {
        if((i%2)!=0)
        {
            for(int j=0; j<i; j++)
            {
				int posLinks = ((anzahl-(i))/2)+1;
				for(int k=0; k<i;k++)
				{
					int hPos = i;
					printArr[hPos][posLinks++] = buchstabe;
				}
            }
        }
    }
    
    for(int k=(anzahl-1); k>=0; k--)
    {
        if((k%2)!=0)
        {
            for (int j=0; j<k; j++)
            {
				int posLinks = ((anzahl-k)/2)+1;
				for(int l=0; l<k;l++)
				{
					int hPos = (anzahl-k) + anzahl;
					printArr[hPos][posLinks++] = buchstabe;
				}
            }
        }
    }

	int increasingFactor = 0;
	for(int m=0; m<_ITEMARRAYSIZE; m++)
	{
		if((m % 2)!=0)
		{
			increasingFactor++;
			for(int n=0; n<_ITEMARRAYSIZE; n++)
			{
				int x = n+sx;
				int y = m+sy;
				if(m==1)
				{
					GoToPos(x, y-1);
				}
				else
				{
					int yCalc = y - increasingFactor;
					GoToPos(x, yCalc);
				}

				char pCh = printArr[m][n];
				if(pCh != NULL)
				{
					printf("%c", pCh);
				}
				else
				{
					printf(" ");
				}
			}
			//printf("\n");
		}
	}
}