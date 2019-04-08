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

int getArrayInt(char* msg, char* msgErr, int min, int max, int reintentos, int* arrayResultado, int limite)
{
    int retorno=-1;
    int i;
    int resultado;

    if(msg!=NULL && msgErr!=NULL && min<=max && reintentos>0 && arrayResultado!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            getInt(msg,msgErr,min,max,reintentos,&resultado);
            *(arrayResultado+i)=resultado;
        }
        retorno=0;
    }


    return retorno;
}

void mostrarArray(int tamano,int* pArray)
{
    int i;
    for(i=0;i<tamano;i++)
    {
        printf("\n%d",*(pArray+i));
    }
}
