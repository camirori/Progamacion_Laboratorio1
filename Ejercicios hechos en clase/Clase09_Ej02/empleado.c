#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#include "empleado.h"

//********************************************************************************
// Inicializar

int empleado_inicializarArrayInt(Empleado array[], int size)
{
    int retorno=-1;
    if(array!=NULL && size>=0)
    {
        for(;size>=0;size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//********************************************************************************
// Buscar
int empleado_buscarPrimerOcurrenciaInt (Empleado array[], int size, int valorBuscado, int* indice)//buscar libre
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if (array[i].isEmpty==valorBuscado)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int empleado_buscarNombre(Empleado array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if (strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//********************************************************************************
// Alta-Baja

int empleado_alta(Empleado array[], int size, int* contadorId)
{
    int posicion;
    char bufferNombres[TEXT_SIZE];

    empleado_buscarPrimerOcurrenciaInt(array,size,1,&posicion);
    printf("%d",posicion);
    if(posicion==-1)    //no encuentra ninguno vacio -1
    {
        printf("\nNo hay lugares libres");
    }
    else
    {
        utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,bufferNombres);
        printf("%s",bufferNombres);
        if(empleado_buscarNombre(array,size,bufferNombres,&posicion)==0 && array[posicion].isEmpty==0)
        {
            printf("\nEl nombre ya existe");
        }
        else
        {
            (*contadorId)++;
            strncpy(array[posicion].nombre,bufferNombres,TEXT_SIZE);                        //cargo el nombre e indico que el lugar está ocupado
            array[posicion].idEmpleado=*contadorId;
            array[posicion].isEmpty=0;
            printf("\nP %d ID %d N %s E %d",posicion, array[posicion].idEmpleado, array[posicion].nombre, array[posicion].isEmpty);
        }
    }

    return 0;
}

int empleado_baja(Empleado array[], int size)
{
    int posicion;
    char bufferNombres[TEXT_SIZE];

    utn_getName("\nNombre a borrar: ","\nError",1,TEXT_SIZE,1,bufferNombres);
    empleado_buscarNombre(array,size,bufferNombres,&posicion);
    if(posicion!=-1)
    {
        array[posicion].isEmpty=1;
    }
    else
    printf("\nEl nombre no existe");

    return 0;
}

//**********************************************************************************************
// Ordenar

int empleado_ordenarporNombre(Empleado array[],int size)
{
    int retorno=-1;
    int i, j;
    char buffer[30];
    int bufferId;
    int bufferIsEmpty;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(buffer,array[i].nombre);
            bufferId=array[i].idEmpleado;
            bufferIsEmpty=array[i].isEmpty;
            j = i - 1;
            while ((j >= 0) && strcmp(buffer,array[j].nombre)<0)     //(j >= 0) > se repite hasta que A[j+1] (i) llega a la posicion 0 o hasta que encuentra uno menor a A[j]
            {
                strcpy(array[j + 1].nombre,array[j].nombre);
                array[j + 1].idEmpleado=array[j].idEmpleado;
                array[j + 1].isEmpty=array[j].isEmpty;               //el valor de la posicion inferior j (que es mayor) pasa a una posición superior j+1/i, el valor de la primer posicion superior esta almacenado en buffer
                j--;                                //chequeo si el primer valor superior (buffer) tmb es mayor a las posiciones anteriores y se van pasando a una posicion superior
            }
            strcpy(array[j + 1].nombre,buffer);
            array[j + 1].idEmpleado=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;                                                 //inserto el primer valor superior (buffer) en la minima posicion alcanzada hasta encontrar uno menor
        }
        retorno=0;
    }
    return retorno;
}

//***********************************************************************************************
// Listar
int empleado_listar(Empleado array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\nID %d N %s",array[i].idEmpleado,array[i].nombre);
        }
        retorno=0;
    }
    return retorno;
}
