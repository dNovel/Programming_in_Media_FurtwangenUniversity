<<<<<<< HEAD
#include <stdio.h>

// Eigene Header
#include "Einstieg.h"
=======
//
//  main.cpp
//  Einstieg
//
//  Created by Dominik Steffen on 12.10.12.
//  Copyright (c) 2012 Dominik Steffen. All rights reserved.
//

#include <stdio.h>
>>>>>>> Mac version of the first lesson
#include "MPLSammlung.h"

#include "EinstiegOSX.h"

int a;
float b;

<<<<<<< HEAD
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
=======
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

>>>>>>> Mac version of the first lesson
