#include <stdio.h>

// Eigene Header
#include "Einstieg.h"
#include "MPLSammlung.h"

int a;
float b;

int main(void)
{
	printf("Hallo Benutzer!\n");
	printf("Bitte Integer eingeben: ");
	scanf("%d", &a);
	printf("Bitte Float eingeben: ");
	scanf("%f", &b);

	printf("Ihre Eingabe von a=%d, Ihre Eingabe von b=%f \n", a, b);

	f1();

	return 0;
}