#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main()
{

    char nombre[10];
    int numero;

    utn_getName("\nNombre ","\nError",1,10,1,nombre);
    printf("%s",nombre);
    //utn_getNumero("\nNumero","\Error",1,6,0,9,1,&numero);
    //printf("%d",numero);


    return 0;
}
