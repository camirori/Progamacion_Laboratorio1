#include <stdio.h>
#include <stdlib.h>

int getChar(char *mensaje, char *mensajeError,float max, float min, int reintentos, char *resultado);
int isValidChar(float min, float max, char valorIngresado);
int solicitoValorChar(char *mensaje, char *valorIngresado);

int main()
{
    char letraIngresada;
    float alturaMax=3;
    float alturaMin=0;
    int reintentos=3;
    char mensajeDatoSolicitado[]="\nLetra: ";
    char mensajeError[]="\nLa letra ingresada es invalida";

    getChar(mensajeDatoSolicitado,mensajeError,alturaMax,alturaMin,reintentos,&letraIngresada);


    printf("\nLa Letra ingresada es: %c",letraIngresada);
    return 0;
}

int getChar(char *mensaje, char *mensajeError,float max, float min, int reintentos, char *resultado)
{
    char valorIngresado;
    int i=0;
    int reintentosRestantes=reintentos;
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL)
    {
        do
        {
            solicitoValorChar(mensaje,&valorIngresado);
            if(isValidChar(min,max,valorIngresado)==0)
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

int isValidChar(float min, float max, char valorIngresado)
{
    if(valorIngresado>min && valorIngresado<max)
    {
        return 1;
    }
    return 0;
}

int solicitoValorChar(char *mensaje, char *valorIngresado)
{
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin);
    scanf("%c",valorIngresado);
    return 0;
}
