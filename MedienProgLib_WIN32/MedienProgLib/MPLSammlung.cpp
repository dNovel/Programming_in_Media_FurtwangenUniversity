#include <stdio.h>
#include <Windows.h>
#include "MPLSammlung.h"

// Groesse des 'grafischen Arrays'
const int _ITEMARRAYSIZE = 32;
char _CurrentStone[_ITEMARRAYSIZE][_ITEMARRAYSIZE] = {};

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


// Zeichnet einen Stein an einer beliebigen X und Y Position in die Konsoles
void Erstelle_Stein(int breite, int hoehe, char buchstabe, int x, int y, int geometryType)
{
	if(geometryType == 0)
	{
		ClearCurrentArray();
	}
	else if(geometryType == 1)
	{
		GetViereckArr(breite, hoehe, buchstabe);
		Zeichne_Stein(x, y);
	}
	else if(geometryType == 2)
	{
		// Anderer Typ usw ...
	}
}


// Zeichnet das Stein Array auf die Konsole an der gewuenschten Stelle
void Zeichne_Stein(int sx, int sy)
{
	// Zeichne
	for(int h=0; h<_ITEMARRAYSIZE; h++)
	{
		// GoToPos(sx, sy+h);
		int tempH = sy+h;
		for(int b=0; b<_ITEMARRAYSIZE; b++)
		{
			GoToPos(sx + b, tempH);
			char buchstabe = _CurrentStone[h][b];
			printf("%c", buchstabe);
		}
	}

	ClearCurrentArray();
	GoToPosZero();
}


// Gibt ein Array mit einem Viereck zurueck
void GetViereckArr(int breite, int hoehe, char buchstabe)
{
	for(int h=0; h<hoehe; h++)
	{
		for(int b=0; b<breite; b++)
		{
			_CurrentStone[h][b] = buchstabe;
		}
	}
}


// Loescht das aktuelle Array damit es wieder sauber ist
void ClearCurrentArray()
{
	char *buchstabe = " ";
	for(int h=0; h<_ITEMARRAYSIZE; h++)
	{
		for(int b=0; b<_ITEMARRAYSIZE; b++)
		{
			_CurrentStone[h][b] = *buchstabe;
		}
	}
}