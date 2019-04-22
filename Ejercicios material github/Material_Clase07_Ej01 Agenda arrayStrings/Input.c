#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

/********************************************************************************************************************************************************************************/
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado al solicitar valor
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar (incluido)
* \param hiLimit Limite superior a validar (incluido)
* \param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \return Si obtuvo el numero [0] sino [-1]
*/
int getInt(int* input,char *message,char *eMessage, int lowLimit, int hiLimit, int reintentos)
{
    int bufferInt;
    int retorno=-1;

    if(message!= NULL && eMessage!= NULL && input!=NULL && lowLimit<hiLimit && reintentos>=0)
    {
        do
        {
            pidoIngresoInt(message,&bufferInt);

            if(isValidInt(bufferInt,hiLimit,lowLimit)==0)
            {
                reintentos--;
                printf("%s, intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *input=bufferInt;
                retorno=0;
                break;
            }
        }
        while(reintentos>0);
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

int pidoIngresoInt(char *mensaje, int *ingreso)
{
    printf("%s",mensaje);
    scanf("%d",ingreso);
    return 0;
}


/********************************************************************************************************************************************************************************/
/**
* \brief Solicita un número flotante al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado al solicitar valor
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char* message,char* eMessage, float lowLimit, float hiLimit, int reintentos)
{
    float bufferFloat;
    int retorno=-1;

    if(message!= NULL && eMessage!= NULL && input!=NULL && lowLimit<hiLimit && reintentos>=0)
    {
        do
        {
            pidoIngresoFloat(message,&bufferFloat);

            if(isValidFloat(bufferFloat,hiLimit,lowLimit)==0)
            {
                reintentos--;
                printf("%s, intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *input=bufferFloat;
                retorno=0;
                break;
            }
        }
        while(reintentos>0);
    }
    return retorno;
}

int isValidFloat(float valorIngresado, float min, float max)
{
    if(valorIngresado>=min && valorIngresado<=max)
    {
        return 1;
    }
    return 0;
}

int pidoIngresoFloat(char *mensaje, float *valorIngresado)
{
    printf("%s",mensaje);
    scanf("%f",valorIngresado);
    return 0;
}

/********************************************************************************************************************************************************************************/
/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado al solicitar valor
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char* message,char* eMessage, char lowLimit, char hiLimit, int reintentos)
{
    char bufferChar;
    int retorno=-1;

    if(message!= NULL && eMessage!= NULL && input!=NULL && lowLimit<hiLimit && reintentos>=0)
    {
        do
        {
            pidoIngresoChar(message,&bufferChar);

            if(isValidInt(bufferChar,hiLimit,lowLimit)==0)
            {
                reintentos--;
                printf("%s, intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *input=bufferChar;
                retorno=0;
                break;
            }
        }
        while(reintentos>0);
    }
    return retorno;
}

int isValidChar(char valorIngresado, char min, char max)
{
    if(valorIngresado>=min && valorIngresado<=max)
    {
        return 1;
    }
    return 0;
}

int pidoIngresoChar(char *mensaje, char *valorIngresado)
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
* \param input Donde se almacena el string ingresado
* \param message Es el mensaje a ser mostrado al solicitar valor
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char* message,char* eMessage, int lowLimit, int hiLimit, int reintentos)
{
    char bufferString;
    int retorno=-1;

    if(message!= NULL && eMessage!= NULL && input!=NULL && lowLimit<hiLimit && reintentos>=0)
    {
        do
        {
            pidoIngresoString(message,&bufferString);

            if(isValidInt(bufferString,hiLimit,lowLimit)==0)
            {
                reintentos--;
                printf("%s, intentos restantes: %d\n",eMessage,reintentos);
                if(reintentos==0)
                {
                    printf("\nSe han agotado los reintentos");
                    break;
                }
            }
            else
            {
                *input=bufferString;
                retorno=0;
                break;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int pidoIngresoString(char *mensaje, char *valorIngresado)
{
    printf("%s",mensaje);
    fflush(stdin); //windows
    //fpurge(stdin); //linux
    fgets(valorIngresado,sizeof(valorIngresado),stdin);
    return 0;
}

int isValidString(char *valorIngresado, char lowLimit, char hiLimit)
{
    if(strlen(valorIngresado)>=lowLimit && strlen(valorIngresado)<=hiLimit)
    {
        return 1;
    }
    return 0;
}

/********************************************************************************************************************************************************************************/
/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado al solicitar valor
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimitInt Limite inferior a validar (incluido)
* \param hiLimitInt Limite superior a validar (incluido)
* \param lowLimitArray Longitud mínima de la cadena
* \param hiLimitArray Longitud máxima de la cadena
* \param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
* \return Si obtuvo la cadena [0] si no [-1]
*
*/

int getArrayInt(int* input,char *message,char *eMessage, int lowLimitInt, int hiLimitInt, int lowLimitArray, int hiLimitArray, int reintentos)
{
    int retorno=-1;
    int i;
    int j;
    int bufferArray[hiLimitArray];
    int bufferInt;

    if(message!= NULL && eMessage!= NULL && input!=NULL && lowLimitInt<hiLimitInt && lowLimitArray<hiLimitArray && reintentos>=0)
    {
        for(i=0;i<hiLimitArray;i++)
        {
            getInt(&bufferInt,message,eMessage,lowLimitInt,hiLimitInt,reintentos);
            *(bufferArray+i)=bufferInt;
        }
        if(isValidArrayInt(bufferArray,lowLimitArray,hiLimitArray))
        {
            for(j=0;j<hiLimitArray;j++)
                *(input+i)=bufferArray[i];
        }
        retorno=0;
    }
    return retorno;
}

int isValidArrayInt(int *valorIngresado, int lowLimit, int hiLimit)
{
    if(sizeof(valorIngresado)/sizeof(int)>=lowLimit && sizeof(valorIngresado)/sizeof(int)<=hiLimit)
    {
        return 1;
    }
    return 0;
}

void mostrarArray(int size,int* pArray)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d",*(pArray+i));
    }
}

