#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CANTIDAD_NUMEROS_A_INGRESAR 5

int ingresoNumeros(void);

int main()
{
    ingresoNumeros();

    return 0;
}

int ingresoNumeros(void)
{
    int i;
    int numeroIngresado;
    int maximoIngresado=INT_MIN;
    int minimoIngresado=INT_MAX;

    for(i=0; i<CANTIDAD_NUMEROS_A_INGRESAR; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numeroIngresado);

        if(numeroIngresado>maximoIngresado)
        {
            maximoIngresado=numeroIngresado;
        }
        if(numeroIngresado<minimoIngresado)
        {
            minimoIngresado=numeroIngresado;
        }
    }
    printf("El maximo ingresado es: %d\n",maximoIngresado);
    printf("El minimo ingresado es: %d\n",minimoIngresado);

    return 0;
}
