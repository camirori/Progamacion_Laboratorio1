#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_INGRESADOS 5


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
        int acumuladorIngresados=0;
        float promedio;

        for(i=0;i<NUMEROS_INGRESADOS;i++)
        {
            printf("\nIngrese un numero: ");
            scanf("%d",&numeroIngresado);
            acumuladorIngresados+=numeroIngresado;
        }
        promedio=(float)acumuladorIngresados/NUMEROS_INGRESADOS;
        printf("El promedio es: %.2f",promedio);

        return 0;
    }

