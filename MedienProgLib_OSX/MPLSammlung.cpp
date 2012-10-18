//
//  MPLSammlung.cpp
//  MedienProgLib
//
//  Created by Dominik Steffen on 12.10.12.
//  Copyright (c) 2012 Dominik Steffen. All rights reserved.
//


#include <stdio.h>
#include "MPLSammlung.h"

void f1()
{
    printf("Ausgabe von f1!");
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
void AusgabeRaute(int anzahl, char buchstabe)
{
    for(int i=1; i<=anzahl; i++)
    {
        if((i%2)!=0)
        {
            for(int j=0; j<i; j++)
            {
                printf("%c", buchstabe);
            }
            printf("\n");
        }
    }
    
    for(int k=(anzahl-1); k>=0; k--)
    {
        if((k%2)!=0)
        {
            for (int j=0; j<k; j++)
            {
                printf("%c", buchstabe);
            }
            printf("\n");
        }
    }
}