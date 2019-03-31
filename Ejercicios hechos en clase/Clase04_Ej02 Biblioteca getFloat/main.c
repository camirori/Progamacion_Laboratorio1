#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    float alturaIngresada;
    float alturaMax=3;
    float alturaMin=0;
    int reintentos=3;
    char mensajeDatoSolicitado[]="\nAltura: ";
    char mensajeError[]="\nLa altura ingresada es invalida";

    getFloat(mensajeDatoSolicitado,mensajeError,alturaMax,alturaMin,reintentos,&alturaIngresada);


    printf("\nLa altura ingresada es: %.2f",alturaIngresada);
    return 0;
}

