#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

/********************************************************************************************************************************************************************************/
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar (incluido)
* \param hiLimit Limite superior a validar (incluido)
* \reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \return Si obtuvo el numero [0] si no [-1]
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit, int reintentos)
{
    int valorIngresado;
    int retorno=-1;

    if(message!= NULL && eMessage!= NULL)
    {
        for(;reintentos>0;)
        {
            pidoIngreso(message,&valorIngresado);

            if(isValidInt(valorIngresado,hiLimit,lowLimit)==0)
            {
                reintentos--;
                printf("\n%s, cantidad de intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *input=valorIngresado;
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}

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


/********************************************************************************************************************************************************************************/
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit, int reintentos)
{
    float valorIngresado;
    int retorno=-1;

    if(message!= NULL && eMessage!= NULL)
    {
        for(;reintentos>0;)
        {
            solicitoValorFloat(message,&valorIngresado);

            if(isValidFloat(lowLimit,hiLimit,valorIngresado)==0)
            {
                reintentos--;
                printf("\n%s, cantidad de intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *input=valorIngresado;
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}

int isValidFloat(float min, float max, float valorIngresado)
{
    if(valorIngresado>=min && valorIngresado<=max)
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

/********************************************************************************************************************************************************************************/
/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit, int reintentos)
{
    char valorIngresado;
    int retorno=-1;

    if(message!= NULL && eMessage!= NULL)
    {
        for(;reintentos>0;)
        {
            solicitoValorChar(message,&valorIngresado);

            if(isValidChar(lowLimit,hiLimit,valorIngresado)==0)
            {
                reintentos--;
                printf("\n%s, cantidad de intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *input=valorIngresado;
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}

int isValidChar(char min, char max, char valorIngresado)
{
    if(valorIngresado>=min && valorIngresado<=max)
    {
        return 1;
    }
    return 0;
}

int solicitoValorChar(char *mensaje, char *valorIngresado)
{
    printf("%s",mensaje);
    fflush(stdin); //windows
    //fpurge(stdin); //linux
    scanf("%c",valorIngresado);
    return 0;
}

/********************************************************************************************************************************************************************************/
/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int reintentos)
{
    int retorno=-1;
    char valorIngresado[hiLimit];

    if(message!=NULL && eMessage!=NULL && lowLimit<=hiLimit && reintentos>0 && input!=NULL)
    {
        for(;reintentos>0;)
        {
            solicitoValorStriing(message,valorIngresado);
            if(isValidString(lowLimit,hiLimit,valorIngresado)==0)
            {
                reintentos--;
                printf("\n%s, cantidad de intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                strcpy(input,valorIngresado);
                break;
            }
        }
        retorno=0;
    }

    return retorno;
}

int solicitoValorStriing(char *mensaje, char *valorIngresado)
{
    printf("%s",mensaje);
    fflush(stdin); //windows
    //fpurge(stdin); //linux
    scanf("%s",valorIngresado);
    return 0;
}

int isValidString(char lowLimit, char hiLimit, char *valorIngresado)
{
    if(strlen(valorIngresado)>=lowLimit && strlen(valorIngresado)<=hiLimit)
    {
        return 1;
    }
    return 0;
}

void mostrarArray(int size,char* pArray)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%c",*(pArray+i));
    }
}
