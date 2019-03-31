/******************************************************************
* Programa: Ejemplo Clase 2
*
* Objetivo:
*   -Realizar un programa que solicite cinco números e imprima por pantalla el
*    promedio, el máximo y el mínimo.
*
* Aspectos a destacar:
*   -El uso de bucles para pedir un número tras otro
*   -El uso de acumuladores, se tiene que guardar la suma para luego hacer
*    el promedio
*   -El uso del if para preguntar si el numero ingresado es mayor o menor
*    para guardar los máximos y mínimos
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS_A_INGRESAR 5

int calculoPromedioMaxMin ();
int analisisMaxMin(int numeroIngresadoP, int* maximoP, int* minimoP);
int imprimoMensaje(float promedioP,int minimoIngresadoP, int maximoIngresadoP);


int main()
{
    calculoPromedioMaxMin ();
    return 0;
}

int calculoPromedioMaxMin ()
{
    int contador;
    int numeroIngresado;
    int acumuladorIngresados=0;
    float promedio;
    int maximoIngresado;
    int minimoIngresado;

    for(contador=0;contador<CANTIDAD_NUMEROS_A_INGRESAR;contador++)
    {
        printf("\nIngrese un numero ");
        scanf("%d",&numeroIngresado);
        acumuladorIngresados+=numeroIngresado;

        if(contador==0)
        {
            minimoIngresado=numeroIngresado;
            maximoIngresado=numeroIngresado;
        }
        else
        {
            analisisMaxMin(numeroIngresado,&maximoIngresado,&minimoIngresado);
        }
    }

    promedio= acumuladorIngresados/CANTIDAD_NUMEROS_A_INGRESAR;

    imprimoMensaje(promedio,minimoIngresado,maximoIngresado);


    return 0;
}

int analisisMaxMin(int numeroIngresadoP, int *maximoP, int *minimoP)
{
        if(numeroIngresadoP>*maximoP)
        {
            *maximoP=numeroIngresadoP;
        }
        if(numeroIngresadoP<*minimoP)
        {
            *minimoP=numeroIngresadoP;
        }
        return 0;
}

int imprimoMensaje(float promedioP,int minimoIngresadoP, int maximoIngresadoP)
{
    printf("\nEl promedio de los numeros ingresados es: %.2f", promedioP);
    printf("\nEl minimo ingresado es %d y el maximo %d",minimoIngresadoP,maximoIngresadoP);

    return 0;
}
