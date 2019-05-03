#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main()
{

    //char nombre[30];
    int numero;


    //utn_getName("\nNombre ","\nError",1,3,2,nombre);
    //printf("Ok %s",nombre);
    //utn_getEmail("\nNumero ","\nError",1,30,1,nombre);
    getNumeroAleatorio(2,5,1,&numero);
    printf("Ok %d",numero);
    getNumeroAleatorio(2,5,0,&numero);
    printf("Ok %d",numero);
    getNumeroAleatorio(2,5,0,&numero);
    printf("Ok %d",numero);
    getNumeroAleatorio(2,5,0,&numero);
    printf("Ok %d",numero);
    getNumeroAleatorio(2,5,0,&numero);
    printf("Ok %d",numero);
    getNumeroAleatorio(2,5,0,&numero);
    printf("Ok %d",numero);


    return 0;
}
