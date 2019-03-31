/******************************************************************
* Programa: Ejemplo Clase 2
*
* Objetivo:
*   -Realizar un programa que solicite cinco n�meros e imprima por pantalla el
*    promedio, el m�ximo y el m�nimo.
*
* Aspectos a destacar:
*   -El uso de bucles para pedir un n�mero tras otro
*   -El uso de acumuladores, se tiene que guardar la suma para luego hacer
*    el promedio
*   -El uso del if para preguntar si el numero ingresado es mayor o menor
*    para guardar los m�ximos y m�nimos
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS_A_INGRESAR 5

int main()
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
            if(numeroIngresado>maximoIngresado)
            {
                maximoIngresado=numeroIngresado;
            }
            if(numeroIngresado<minimoIngresado)
            {
                minimoIngresado=numeroIngresado;
            }
        }

    }

    promedio= acumuladorIngresados/CANTIDAD_NUMEROS_A_INGRESAR;

    printf("\nEl promedio de los numeros ingresados es: %.2f", promedio);
    printf("\nEl minimo ingresado es %d y el maximo %d",minimoIngresado,maximoIngresado);



    return 0;
}
