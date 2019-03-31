#include <stdio.h>
#include <stdlib.h>


int isValidInt(int numero,int max, int min)
{
    if(numero>=min && numero<=max)
    {
        return 1;
    }
        return 0;
}

int pidoIngreso(char *mensaje, int *ingreso)
{
    printf("%s",mensaje);
    scanf("%d",ingreso);
    return 0;
}

int getInt(char *mensaje,char *mensajeError,int min,int max,int reintentos,int *resultado)
{
    int i;
    int valorIngresado;
    int retorno=-1;
    int reintentosRestantes=reintentos;

    if(mensaje!= NULL && mensajeError!= NULL)
    {
        for(i=0;i<reintentos;i++)
        {
            pidoIngreso(mensaje,&valorIngresado);

            if(isValidInt(valorIngresado,max,min)==0)
            {
                reintentosRestantes--;
                printf("%s, cantidad de intentos restantes: %d",mensajeError,reintentosRestantes);
                if(reintentosRestantes==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *resultado=valorIngresado;
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}
