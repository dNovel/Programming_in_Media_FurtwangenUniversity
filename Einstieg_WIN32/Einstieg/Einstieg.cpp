#include <stdio.h>

// Eigene Header
#include "Einstieg.h"
#include "MPLSammlung.h"

int a;
float b;

int main(int argc, const char * argv[])
{
    printf("Bitte einen Interger eingeben: \n");
    scanf("%d", &a);
    
    printf("Bitte einen Float eingeben: \n");
    scanf("%f", &b);
    
    printf("Ihre Eingabe fuer a=%d, Ihre Eingabe fuer b=%f \n", a, b);
    
    f1(); // Von der static lib.
    
    return 0;
}