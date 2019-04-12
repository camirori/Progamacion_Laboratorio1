#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0

int getString(  char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                )
{
    int retorno=-1;
    char bufferStr[60];
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
        while(reintentos>=0);
    }
    return retorno;
}
//------------------------------
int getName(    char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                )
{
    int retorno=-1;
    char bufferStr[60];

    if(msg!=NULL && msgError!=NULL && min<max && reintentos>=0 && resultado!=NULL)
    {
        if(!getString(msg,msgError,min,max,reintentos,bufferStr)) //==0
        {
            if(isValidName(bufferStr)==1)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
            }
        }
    }

    return retorno;
}



//------------------------------

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
