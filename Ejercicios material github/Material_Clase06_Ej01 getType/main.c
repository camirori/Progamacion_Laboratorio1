/******************************************************************
* Programa: Ejemplo Clase 6
*
* Objetivo:
*   1-Agregar a la  biblioteca utn.h  funciones para validar diferentes
*     tipos de valores:
*       Solo números, ej. 123436679
*       Solo letras, ej. abBD
*       Alfanumericos, ej. ab555gT6
*       Teléfono, ej. 4XXX-XXXX
*   2-Realizar un programa que pida al usuario el ingreso de un dato y
*     determine con cuales de los tipos cumple
*
* Aspectos a destacar:
*   Manipulación y chequeo de cadena de caracteres
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getType(char* input);

int main()
{
    char input[30];
    int reintentos=1;

    getString("Ingrese un dato (numero, alfanumerico o telefono)","Error",1,30,&reintentos,input);
    getType(input);

    return 0;
}

// *   1-Agregar a la  biblioteca utn.h  funciones para validar diferentes tipos de valores: >>> Biblioteca utn

// *   2-Realizar un programa que pida al usuario el ingreso de un dato y determine con cuales de los tipos cumple

int getType(char* input)
{
    int retorno=-1;
    if(input!=NULL)
    {
        if(isValidNumber(input)==1)
        {
            printf("\nEl dato ingresado es un numero");
        }
        else if(isValidTelephone(input)==1)
        {
            printf("\nEl dato ingresado puede ser un numero telefonico");
        }
        else if(isValidName(input)==1)
        {
            printf("\nEl dato ingresado contiene solo letras");
        }
        else if(isValidAlphanumeric(input)==1)
        {
            printf("\nEl dato ingresado es alfanumerico");
        }
        else
            printf("\nEl dato ingresado no corresponde a ningun tipo");

        retorno=0;
    }
    return retorno;
}
