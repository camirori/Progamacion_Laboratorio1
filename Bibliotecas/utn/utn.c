#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getString(  char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                )
{
    int retorno=-1;
    char bufferStr[max+1];

    if(msg!=NULL && msgError!=NULL && min<max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s",msgError);
            reintentos--;
        }
        while(reintentos>0);
    }
    return retorno;
}
//------------------------------
int utn_getName(    char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                )
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<max && reintentos>=0 && resultado!=NULL)
    {
        if(!getString(msg,msgError,min,max,reintentos,bufferStr)) //==0
        {
            if(isValidName(bufferStr)==1)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
            }
            else{printf("%s",msgError);}
        }
    }

    return retorno;
}


int isValidName(char* stringRecibido)   //si fuera un numero podrìa necesitar parametros para validar max y min
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')
        // o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=0;
            break;
        }
    }


    return retorno;
}

//-----------------------------------------

int utn_getNumero(  char* msg,
                    char* msgError,
                    int minSize,    //cantidad de caracteres
                    int maxSize,
                    int min,
                    int max,
                    int reintentos,
                    int* input)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        if(!getString(msg,msgError,minSize,maxSize,reintentos,bufferStr)) //==0 sin errores !0
        {
            if(isValidName(bufferStr)==1)
            {
                *input=atoi(bufferStr);
                retorno=0;
            }
        }
    }

    return retorno;
}

int isValidNumber(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }


    return retorno;
}
//-------------------------------------------------
/*
utn_getNumeroConSigno

utn_getNumeroConDecimales
utn_getTelefono
utn_getDNI
utn_getCUIT
utn_getEmail
utn_getTexto
*/
