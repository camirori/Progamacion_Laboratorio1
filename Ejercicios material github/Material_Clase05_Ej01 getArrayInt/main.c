/******************************************************************
* Programa: Ejemplo Clase 5
*
* Objetivo:
*   Solicitar al usuario 5 números, permitir listarlos por pantalla
*   indicando el máximo, el mínimo y el promedio
*   Permitir Modificar el valor de cualquiera de los números cargados
*   indicando el índice del mismo y su nuevo valor.
*
* Aspectos a destacar:
*   -Utilización de array
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>

int getInt(int cantidadSolicitados, int *valoresIngresados);
int maxMinPromedio(int cantidadSolicitados, int *valoresIngresados, int *max, int *min, int *promedio);



int main()
{
    int numerosIngresados[6];
    int cantidadSolicitados=5;
    int i;
    int maximoIngresado;
    int minimoIngresado;
    int promedioIngresado;

    getInt(cantidadSolicitados,numerosIngresados);

    printf("\nLos numeros ingresados son:");
    for(i=0;i<cantidadSolicitados;i++)
    {
        printf("\nIndice %d: %d",i,numerosIngresados[i]);
    }

    maxMinPromedio(cantidadSolicitados, numerosIngresados, &maximoIngresado, &minimoIngresado,&promedioIngresado);

    printf("\nMaximo ingresado: %d \nMinimo ingresado: %d \nPromedio: %d",maximoIngresado,minimoIngresado,promedioIngresado);

    return 0;
}


int getInt(int cantidadSolicitados, int *valoresIngresados)
{
    int i;
    int retorno=-1;

    for(i=0;i<cantidadSolicitados;i++)
    {
        printf("\nIngrese un numero ");
        scanf("%d",(valoresIngresados+i));
        retorno=0;
    }

    return retorno;
}

int maxMinPromedio(int cantidadSolicitados, int *valoresIngresados, int *max, int *min, int *promedio)
{
    int i;
    *max=*valoresIngresados;
    *min=*valoresIngresados;
    int acumulado=*valoresIngresados;

    for(i=1;i<cantidadSolicitados;i++)
    {
        if(*(valoresIngresados+i)>*max)
        {
            *max=*(valoresIngresados+i);
        }
        if(*(valoresIngresados+i)<*min)
        {
            *min=*(valoresIngresados+i);
        }
        acumulado+=*(valoresIngresados+i);
    }
    *promedio=acumulado/cantidadSolicitados;

    return 0;
}
