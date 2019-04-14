#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ARRAY 10

int getString(char*input,char message[],char eMessage[], int hiLimit, int reintentos, int size);
int solicitoValorString(char *mensaje, char *valorIngresado);
int isValidString(char hiLimit, char *valorIngresado);


int main()
{
    char nombre[SIZE_ARRAY];

    getString(nombre,"\nIngrese un nombre ","\nNombre no valido", SIZE_ARRAY-1, 3,sizeof(nombre));

    printf("\n%s",nombre);

    return 0;
}

int getString(char*input,char message[],char eMessage[], int hiLimit, int reintentos, int size)
{
    int retorno=-1;
    char buffer[strlen(input)];

    if(input!=NULL && message!=NULL && eMessage!=NULL)
    {
        for(;reintentos>0;)
        {
            solicitoValorString(message,buffer);
            if(isValidString(hiLimit,buffer)==0)
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
                strncpy(input,buffer,size); //size lo paso por parametro, si pongo sizeof(puntero) va a dar 1

                break;
            }
        }
        retorno=0;
    }
    return retorno;
}

int solicitoValorString(char *mensaje, char *valorIngresado)
{
    printf("%s",mensaje);
    fflush(stdin); //windows
    //fpurge(stdin); //linux
    fgets(valorIngresado,sizeof(valorIngresado),stdin);
    return 0;
}

int isValidString(char hiLimit, char *valorIngresado)
{
    int i;
    int retorno=-1;
    if(strlen(valorIngresado)<=hiLimit)
    {
        retorno=1;
        for(i=0;i<strlen(valorIngresado)-1;i++) //strlen incluye el 0
        {
            if(*(valorIngresado+i)<'A' || (*(valorIngresado+i)>'Z' && *(valorIngresado+i)<'a') || *(valorIngresado+i)>'z')
            {
                return 0;
            }
        }
    }
    return retorno;
}
