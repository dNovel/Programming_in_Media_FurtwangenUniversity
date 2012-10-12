// Medienprogrammieren Stunde 1

#include "MPLSammlung.h"
#include "EinstiegOSX.h"

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
