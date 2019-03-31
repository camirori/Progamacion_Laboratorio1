#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int edadIngresadaMinimo=0;
    int edadIngresadaMaximo=100;
    int reintentosIngreso=3;
    char mensajeIngreso[]="\nEdad ";
    char mensajeError[]="\nEdad invalida";
    int edadIngresada;

    getInt(mensajeIngreso,mensajeError,edadIngresadaMinimo,edadIngresadaMaximo,reintentosIngreso,&edadIngresada);

    printf("\nLa edad ingresada es: %d",edadIngresada);
    return 0;
}

