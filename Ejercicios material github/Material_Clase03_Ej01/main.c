/******************************************************************
* Programa: Ejemplo Clase 3
*
* Objetivo:
*   -Crear una función que permita ingresar un numero al usuario y lo retorne.
*   -Crear una función que reciba el radio de un círculo y retorne su área
*   -Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
*    el área de un círculo cuyo radio es ingresado por el usuario
*   -Documentar las funciones al estilo Doxygen
*
* Aspectos a destacar:
*   -Declaración de funciones que devuelven y reciben valores
*   -Hacer notar que el uso de funciones evita el código repetido y ayuda a que
*    el mismo sea mas legible
*   -La función debería comenzar indicando el objetivo que persigue y el
*    significado de sus parámetros.
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ingresoNumero (int *numeroIngresado);
int calculoArea(int radioP, int *areaP);


int main()
{
    int area;
    int numeroIngresado;

    ingresoNumero (&numeroIngresado);
    calculoArea(numeroIngresado,&area);

    printf("El area es: %d", area);
    return 0;
}

int ingresoNumero (int *numeroIngresado)
{
    printf("Ingrese un numero");
    scanf("%d",numeroIngresado);

    return 0;
}
int calculoArea(int radioP, int *areaP)
{
    *areaP=M_PI*radioP*radioP;

    return 0;
}
