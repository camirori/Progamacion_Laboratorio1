/******************
Hacer un programa con el siguiente menu:
   1) ingresar nuevo nombre (no acepta nombres repetidos)
   2) listar todo
   3) ordenar por nombre
   4) Borrar nombre. Se ingresa el nombre y si se encuentra se elimina de la lista

El programa permitira ingresar hasta 100 nombres.

4) Modificar el programa para que ademas del nombre se ingrese y guarde el DNI.


*///////////////////

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"


#define QTY_EMPLEADOS 3
#define TEXT_SIZE 20

int main()
{
    int opcion=0;
    int posicion;

    char arrayNombres[QTY_EMPLEADOS][TEXT_SIZE];
    char bufferNombres[TEXT_SIZE];

    array_inicializarArrayString(arrayNombres,QTY_EMPLEADOS);

    do
    {
        utn_getNumero("\n\n1) ingresar nuevo nombre (no acepta nombres repetidos) \n2) listar todo \n3) ordenar por nombre \n4) Borrar nombre \n5) Salir\n","\nError",1,2,1,5,1,&opcion);
        switch(opcion)
        {
            case 1:
                posicion=array_buscarPrimerOcurrenciaString(arrayNombres,QTY_EMPLEADOS,"");
                if(posicion==-1)    //no encuentra ninguno vacio -1
                {
                    printf("\nNo hay lugares libres");
                }
                else
                {
                    utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,bufferNombres);
                    printf("%s",bufferNombres);
                    if(array_buscarPrimerOcurrenciaString(arrayNombres,QTY_EMPLEADOS,bufferNombres)!=-1)
                    {
                        printf("\nEl nombre ya existe");
                    }
                    else
                    {
                        strncpy(arrayNombres[posicion],bufferNombres,TEXT_SIZE);
                    }
                }
                strcpy(bufferNombres,"");
                posicion=-1;
                break;

            case 2:
                array_listarArrayString(arrayNombres,QTY_EMPLEADOS);
                break;

            case 3:
                array_ordenarPorInsercionString(arrayNombres,QTY_EMPLEADOS);
                break;

            case 4:
                utn_getName("\nNombre a borrar: ","\nError",1,TEXT_SIZE,1,bufferNombres);
                posicion=array_buscarPrimerOcurrenciaString(arrayNombres,QTY_EMPLEADOS,bufferNombres);
                if(posicion!=-1)
                {
                    strncpy(arrayNombres[posicion],"",TEXT_SIZE);
                }
                else
                    printf("\nEl nombre no existe");

                break;

            case 5:
                break;
        }
    }
    while(opcion!=5);

    return 0;
}

// inicializar todas las posiciones de indice A en algo para analizar si estan ocupados, por mas que se ocupe luego reemplazo solo el primer elemento para decir que ya no se usa
//funciòn que busque la posiciòn del array que se encuentra vacia

