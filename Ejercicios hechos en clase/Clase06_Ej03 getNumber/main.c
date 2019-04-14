#include <stdio.h>
#include <stdlib.h>

int utn_isValidString(char *str);
int utn_getString(char *msg, char *msgError, int min, int max, int reintentos, char *resultado); //minMax son cantidad de caracteres
int utn_getNumber(char *msg, char *msgError, int min, int max, int reintentos, int *resultado);


int main()
{



    printf("Hello world!\n");
    return 0;
}

int utn_isValidNumber(char *str)
{
    return 1;
}

int utn_getString(char *msg, char *msgError, int min, int max, int reintentos, char *resultado)
{
    strncpy(resultado,"1234",5);
    return 0;
}

int utn_getNumber(char *msg, char *msgError, int min, int max, int reintentos, int *resultado)
{
    int retorno;=-1;
    char buffer[18];
    int bufferInt;
    if(msg!=NULL && msgError!=NULL && resultado!=NULL && min<max && reintentos>=0)
    {
        if(utn_getString(msg,msgError,1,16,reintentos,buffer)==0)
        {
            if(utn_isValidNumber(buffer))
                bufferInt=atoi(buffer);
                if(bufferInt>=min && bufferInt<=max)
                {
                    *resultado=bufferInt;
                    retorno=0;
                }
        }
    }
    return retorno;
}
