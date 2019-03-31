
#include <stdio.h>
#include <stdlib.h>

int isValidFloat(float min, float max, float valorIngresado)
{
    if(valorIngresado>min && valorIngresado<max)
    {
        return 1;
    }
    return 0;
}

int solicitoValorFloat(char *mensaje, float *valorIngresado)
{
    printf("%s",mensaje);
    scanf("%f",valorIngresado);
    return 0;
}

int getFloat(char *mensaje, char *mensajeError,float max, float min, int reintentos, float *resultado)
{
    float valorIngresado;
    int i=0;
    int reintentosRestantes=reintentos;
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL)
    {
        do
        {
            solicitoValorFloat(mensaje,&valorIngresado);
            if(isValidFloat(min,max,valorIngresado)==0)
            {
                reintentosRestantes--;
                printf("%s, reintentos restantes: %d",mensajeError,reintentosRestantes);
            }
            else
            {
                *resultado=valorIngresado;
                retorno=0;
                break;
            }
            i++;
        }
        while(i<reintentos);
    }


    return retorno;
}


