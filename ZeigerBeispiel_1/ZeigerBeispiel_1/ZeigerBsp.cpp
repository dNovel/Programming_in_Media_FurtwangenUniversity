// Erstes Zeiger Beispiel Programm im WS 2012/2013
#include <stdio.h>;
#include "ZeigerBsp.h";



void main(void)
{
	int a = 2;
	printf("Wir initialisieren a, es hat den Wert %d \n", a);
	int b = 4;
	// printf("Wir initialisieren a, es hat den Wert %d \n", b);
	int c = 8;
	// printf("Wir initialisieren a, es hat den Wert %d \n", c);

	// Deklariere Pointer 'zA'
	int *zA;
	printf("Wir deklarieren zA als Pointer \n");

	zA = &a;
	printf("zA = &a; ... zA enthaelt jetzt die Adresse von a \n");


	printf("Was kommt hierbei wohl raus wenn wir \"zA\" ausgeben? %d \n", zA);
	printf("Was kommt hierbei wohl raus wenn wir \"*zA\" ausgeben? %d \n", *zA);
	printf("Was kommt hierbei wohl raus wenn wir \"&zA\" ausgeben? %d \n", &zA);

	printf("\n \n");
	printf("Warum ist das wohl so? \n Bedenke,\n & = Adresse oder adress,\n * = Zeiger oder pointer,\n 'nichts vorne dran' entspricht dem direkten Wert einer Variable.");
}