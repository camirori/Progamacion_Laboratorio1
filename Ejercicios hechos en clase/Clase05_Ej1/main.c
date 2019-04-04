#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define CANTIDAD_ALUMNOS 3

int main()
{
    /*
    int* pEdades;
    int bufferEdad;
    int aEdades[CANTIDAD_ALUMNOS];
    //float aEdades[CANTIDAD_ALUMNOS];
    //char aLetraNombre[CANTIDAD_ALUMNOS];

    aEdades[100]=22;
    bufferEdad=aEdades[100];

    pEdades=aEdades; //= pEdades=&aEdades[0];

    *(pEdades+88)=11; // = pEdades[88] = 11; indica que en la posicion 0+88 se guarda el valor 11
    bufferEdad=*(pEdades+188); // bufferEdad=pEdades[188];*/

    char msg[]="\nIngrese la edad ";
    char msgErr[]="\nLa edad ingresada no es valida";
    int min=0;
    int max=130;
    int reintentos=3;
    int aEdades[CANTIDAD_ALUMNOS];
    int limite=CANTIDAD_ALUMNOS;


    if(getArrayInt(msg,msgErr,min,max,reintentos,aEdades,limite)==0)
    {
        printf("\nLas edades ingresadas son: ");
        mostrarArray(limite,aEdades);
    }
    else
    {
        printf("\nError");
    }

    return 0;
}

