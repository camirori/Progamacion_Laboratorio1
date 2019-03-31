#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS_INGRESADOS 5

int ingresoNumeros();
int calcularPromedio(int valorAcumulado, int cantidad, float *promedio);

int main()
{
    ingresoNumeros();
    calcularPromedio();

    return 0;
}

int ingresoNumeros()
    {
        int i;
        int numeroIngresado;
        int valorAcumulado=0;
        float promedio;

        for(i=0;i<CANTIDAD_NUMEROS_INGRESADOS;i++)
        {
            printf("\nIngrese un numero: ");
            scanf("%d",&numeroIngresado);
            valorAcumulado+=numeroIngresado;
        }
        promedio=valorAcumulado/CANTIDAD_NUMEROS_INGRESADOS;

        if(calcularPromedio(valorAcumulado,CANTIDAD_NUMEROS_INGRESADOS,&promedio)==0)
        {
            printf("El promedio es: %.2f",promedio);
        }
        else
        {
            printf("Error");
        }

        return 0;
    }

int calcularPromedio(int valorAcumulado, int cantidad, float *promedio)
{
    int retorno=-1;
    if(cantidad > 0 && promedio != NULL)
    {
         *promedio=(float)valorAcumulado/cantidad;
         retorno=0;
    }

    return retorno;
}
