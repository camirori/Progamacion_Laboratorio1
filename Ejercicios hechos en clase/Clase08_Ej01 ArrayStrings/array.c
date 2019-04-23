#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Input.h"
#include "utn.h"
#include "array.h"

#define SIZE_TEXTO 20

//********************************************************************************
// Inicializar

int array_inicializarArrayString(char array[][SIZE_TEXTO], int size)
{
    int retorno=-1;
    if(array!=NULL && size>=0)
    {
        for(;size>=0;size--)
        {
            strcpy(array[size],"");
        }
        retorno=0;
    }
    return retorno;
}
int array_inicializarArrayInt(int* array, int size, int valor)
{
    int retorno=-1;
    if(array!=NULL && size>=0)
    {
        for(;size>=0;size--)
        {
            array[size]=valor;
        }
        retorno=0;
    }
    return retorno;
}

//********************************************************************************
// Cargar
/*
int array_cargaSecuencialArrayInt(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input)
{
    int i;
    for(i=0;i<maxSize;i++)
    {
        utn_getNumero(msg,msgError,minSize,maxSize,min,max,reintentos,input);
    }
    return 0;
}*/
/*
int array_cargaSecuencialArrayString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int i;
    for(i=0;i<maxSize;i++)
    {
        utn_getName(msg,msgError,min,max,reintentos,resultado);
    }
    return 0;
}*/

//cargaAleatoria

//********************************************************************************
// Buscar
int array_buscarPrimerOcurrenciaInt (int* array, int size, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if (array[i]==valorBuscado)
            {
                retorno=i;
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}

int array_buscarPrimerOcurrenciaString(char array[][SIZE_TEXTO], int size, char* valorBuscado)
{
    int retorno=-1;                                         //si no encuentra devuelve -1
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if (strcmp(array[i],valorBuscado)==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

//***********************************************************************************************
// Listar
int array_listarArrayIntString(int* array1, char array2[][SIZE_TEXTO], char array3[][SIZE_TEXTO], int size)  // no se puede hacer sin sizetexto?
{
    int retorno=-1;
    int i;
    if(array1!=NULL && array2!=NULL && array3!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array1[i]==-1)
                continue;
            else
                printf("\nL %d N %s A %s",array1[i],array2[i],array3[i]);
        }
        retorno=0;
    }
    return retorno;
}
int array_listarArrayInt(int* array, int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i]==-1)
                continue;
            else
                printf("\n%d",array[i]);
        }
        retorno=0;
    }
    return retorno;
}

int array_listarArrayString(char array[][SIZE_TEXTO], int size)  // no se puede hacer sin sizetexto?
{
    int retorno=-1;
    int i;
    if(array!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(strcmp(array[i],"")==0)
                continue;
            else
            printf("\n%s",array[i]);
        }
        retorno=0;
    }
    return retorno;
}

//**********************************************************************************************
// Ordenar


//Ordenación por selección: para arrays pequeños
//Ordenación por inserción: usar Si la entrada esta "casi ordenada"
//Ordenación de Shell (ShellSort): para ordenar entradas de datos moderadamente grandes
//Ordenación por montículos (Heapsort)
//Ordenación por Intercalación (mergesort)
//Ordenación rápida (quicksort)

// Ordenar ArrayInt
int array_ordenarPorSeleccion(int* array, int size)
{
    int retorno=-1;
    int i, j, k;
    int buffer;
    if(array!=NULL && size>=0)
    {
        for (i = 0; i < size - 1; i++)
        {
            for (k = i, j = i + 1; j < size; j++)
            {
                if (array[j] < array[k])
                    k = j;
                if (k != i)                     // si k==i es porque A[i(k)]<A[i+1(j)]
                {
                    buffer = array[i];
                    array[i] = array[j];
                    array[j] = buffer;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int array_ordenarPorInsercion(int* array, int size)
{
    int retorno=-1;
    int i, j;
    int buffer;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            buffer = array[i];
            j = i - 1;
            while ((j >= 0) && (buffer < array[j]))     //(j >= 0) > se repite hasta que A[j+1] (i) llega a la posicion 0 o hasta que encuentra uno menor a A[j]
            {
                array[j + 1] = array[j];            //el valor de la posicion inferior j (que es mayor) pasa a una posición superior j+1/i, el valor de la primer posicion superior esta almacenado en buffer
                j--;                                //chequeo si el primer valor superior (buffer) tmb es mayor a las posiciones anteriores y se van pasando a una posicion superior
            }
            array[j + 1] = buffer;                  //inserto el primer valor superior (buffer) en la minima posicion alcanzada hasta encontrar uno menor
        }
        retorno=0;
    }

    return retorno;
}

int array_ordenarShell(int* array, int size)          //es en realidad una ordenación por inserción pero a la cual se le pasa el array "casi ordenado"
{
    int retorno=-1;
    int incr = size / 2, p, j;
    int tmp;
    if(array!=NULL && size>=0)
    {
        do
        {
            for (p = incr + 1; p < size; p++)           //tomo un elemento de la segunda mitad, desde abajo para arriba
            {
                tmp = array[p];                         //se almacena el elemento a comparar
                j = p - incr;                           //se compara con los elementos de la primera mitad desde j-mitad hacia abajo, pero no todos
                while ((j >= 0) && (tmp < array[j]))
                {
                    array[j + incr] = array[j];         //paso el valor de la primera mitad array[j] a la segunda array[j + incr]
                    j -= incr;                          //comparo el valor almacenado de la segunda mitad con otro de la primera
                }
                array[j + incr] = tmp;
            }
            incr /= 2;                                  //voy a tomar un elemento desde la mitad de la mitad, hasta llegar al elemento 2
        } while (incr > 0);
        retorno=0;
    }
    return retorno;
}

//Ordenar arrayString
int array_ordenarPorInsercionString(char array[][SIZE_TEXTO], int size)
{
    int retorno=-1;
    int i, j;
    char buffer[30];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(buffer,array[i]);
            j = i - 1;
            while ((j >= 0) && strcmp(buffer,array[j])<0)     //(j >= 0) > se repite hasta que A[j+1] (i) llega a la posicion 0 o hasta que encuentra uno menor a A[j]
            {
                strcpy(array[j + 1],array[j]);            //el valor de la posicion inferior j (que es mayor) pasa a una posición superior j+1/i, el valor de la primer posicion superior esta almacenado en buffer
                j--;                                //chequeo si el primer valor superior (buffer) tmb es mayor a las posiciones anteriores y se van pasando a una posicion superior
            }
            strcpy(array[j + 1],buffer);            //inserto el primer valor superior (buffer) en la minima posicion alcanzada hasta encontrar uno menor
        }
        retorno=0;
    }
    return retorno;
}




