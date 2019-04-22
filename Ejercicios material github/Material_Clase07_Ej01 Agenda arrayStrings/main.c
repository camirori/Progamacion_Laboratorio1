/******************************************************************
* Programa: Ejemplo Clase 7
*
* Objetivo:
*   Realizar una agenda para guardar los datos de hasta 200 personas
*   de las cuales se toman los siguientes datos:
*       Nombre
*       Apellido
*       legajo (NO SE PUEDE REPETIR)
*
*   a- Realizar un programa con un menú de opciones para hacer altas ,
*      bajas y modificaciones (ABM) de una agenda.
*   b- Mostrar un listado ordenado por Apellido
*
* Aspectos a destacar:
*   Manipulación y chequeo de cadena de caracteres
*   arrays paraleos
*   bajas logicas
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "utn.h"

#define QTY_CLIENTES 5
#define SIZE_TEXTO 5

int inicializarArrayString(char array[][SIZE_TEXTO], int size);
int inicializarArrayInt(int* array, int size, int valor);
int buscarPrimerOcurrencia(int* array, int size, int valorBuscado);
int listarArrays(int* array1, char array2[][SIZE_TEXTO], char array3[][SIZE_TEXTO],  int size);
int ordenarPorInsercionString(char arrayOrdenar[][SIZE_TEXTO], char arrayY[][SIZE_TEXTO], int* arrayInt, int size);
int listarArrayString(char array[][SIZE_TEXTO], int size);



int main()
{
    char nombre [QTY_CLIENTES][SIZE_TEXTO];
    char apellido [QTY_CLIENTES][SIZE_TEXTO];
    int legajo [QTY_CLIENTES];
    int auxLegajo;
    int opcion;
    int lugarLibre=-1;
    int posicion;
    char opcion3;


    inicializarArrayInt(legajo,QTY_CLIENTES,-1);
    inicializarArrayString(nombre,QTY_CLIENTES);
    inicializarArrayString(apellido,QTY_CLIENTES);

    do
    {
        getInt(&opcion,"\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n","Error",1,6,3);
        switch(opcion)
        {
            case 1: //Alta
                lugarLibre=buscarPrimerOcurrencia(legajo,QTY_CLIENTES,-1);
                printf("\nLibre %d",lugarLibre);
                if(lugarLibre==-1)
                {
                    printf("\nNo quedan lugares libres");
                    break;
                }

                printf("\nAlta: ");
                utn_getNumero("\nLegajo: ","\nError",1,3,1,QTY_CLIENTES,1,&auxLegajo);
                if(buscarPrimerOcurrencia(legajo,QTY_CLIENTES,auxLegajo)!=-1)
                {
                    printf("\nEl legajo ya existe");
                }
                else
                {
                    if(utn_getName("\nNombre: ","\nError",1,SIZE_TEXTO,1,&nombre[lugarLibre][0])==0
                       && utn_getName("\nApellido: ","\nError",1,SIZE_TEXTO,1,&apellido[lugarLibre][0])==0)
                    {
                        legajo[lugarLibre]=auxLegajo;
                    }
                    printf("L %d N %s A %s",legajo[lugarLibre],nombre[lugarLibre],apellido[lugarLibre]);
                }

                break;
            case 2: //Baja
                utn_getNumero("\nLegajo a eliminar: ","\nError",1,3,1,QTY_CLIENTES,1,&auxLegajo);
                legajo[buscarPrimerOcurrencia(legajo,QTY_CLIENTES,auxLegajo)]=-1;

                break;
            case 3: //modificacion
                utn_getNumero("\nLegajo a modificar: ","\nError",1,3,1,QTY_CLIENTES,1,&auxLegajo);      //pide numero de legajo
                posicion=buscarPrimerOcurrencia(legajo,QTY_CLIENTES,auxLegajo);                         //busca la posicion en la que se encuentra
                if(posicion==-1)
                {
                    printf("El legajo no existe");                                                      // si no lo encuentra lo informa
                }
                else
                {
                    do
                    {
                        printf("L %d N %s A %s ",legajo[posicion],nombre[posicion],apellido[posicion]);         //pregunta qué modificar de ese legajo
                        getChar(&opcion3,"\nQue desea modificar? L N A S(Salir)","Error",'A','S',1);
                        switch(opcion3)
                        {
                            case 'L':
                                utn_getNumero("\nLegajo: ","\nError",1,3,1,QTY_CLIENTES,1,&auxLegajo);
                                if(buscarPrimerOcurrencia(legajo,QTY_CLIENTES,auxLegajo)!=-1)
                                {
                                    printf("\nEl legajo ya existe");
                                }
                                else
                                {
                                    legajo[posicion]=auxLegajo;
                                }
                                break;

                            case 'N':
                                utn_getName("\nNombre: ","\nError",1,SIZE_TEXTO,1,&nombre[posicion][0]);
                                break;

                            case 'A':
                                utn_getName("\nApellido: ","\nError",1,SIZE_TEXTO,1,&apellido[posicion][0]);
                                break;

                            case 'S':
                                break;
                        }
                    }
                    while(opcion3!='S');
                }
                break;

            case 4: //listar
                listarArrays(legajo,nombre,apellido,QTY_CLIENTES);
                break;

            case 5: //ordenar
                ordenarPorInsercionString(apellido,nombre,legajo,QTY_CLIENTES);
                break;

            case 6: //Salir
                break;
        }
    }
    while(opcion!=6);

    return 0;
}


// Biblioteca array
// inicializarArrayInt
// buscarPrimerOcurrencia
// alta
// baja
// modificacion
// ordenar

int inicializarArrayString(char array[][SIZE_TEXTO], int size)
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
int inicializarArrayInt(int* array, int size, int valor)
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
int buscarPrimerOcurrencia (int* array, int size, int valorBuscado)
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
    }
    return retorno;
}

int listarArrays(int* array1, char array2[][SIZE_TEXTO], char array3[][SIZE_TEXTO], int size)  // no se puede hacer sin sizetexto?
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

int listarArrayString(char array[][SIZE_TEXTO], int size)  // no se puede hacer sin sizetexto?
{
    int retorno=-1;
    int i;
    if(array!=NULL)
    {
        for(i=0;i<size;i++)
        {
            printf("\n%d %s.",i,array[i]);
        }
        retorno=0;
    }
    return retorno;
}

int ordenarPorInsercionString(char arrayOrdenar[][SIZE_TEXTO], char arrayY[][SIZE_TEXTO], int* arrayInt, int size)
{
    int retorno=-1;
    int i, j;
    char buffer[SIZE_TEXTO];
    char buffer2[SIZE_TEXTO];
    int buffer3;

    if(arrayOrdenar!=NULL && arrayY!=NULL && arrayInt!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(buffer,arrayOrdenar[i]);
            strcpy(buffer2,arrayY[i]);
            buffer3=arrayInt[i];

            j = i - 1;
            while ((j >= 0) && strcmp(buffer,arrayOrdenar[j])<0)     //(j >= 0) > se repite hasta que A[j+1] (i) llega a la posicion 0 o hasta que encuentra uno menor a A[j]
            {
                strcpy(arrayOrdenar[j + 1],arrayOrdenar[j]);            //el valor de la posicion inferior j (que es mayor) pasa a una posición superior j+1/i, el valor de la primer posicion superior esta almacenado en buffer
                strcpy(arrayY[j + 1],arrayY[j]);
                arrayInt[j + 1]=arrayInt[j];
                j--;                                //chequeo si el primer valor superior (buffer) tmb es mayor a las posiciones anteriores y se van pasando a una posicion superior
            }
            strcpy(arrayOrdenar[j + 1],buffer);            //inserto el primer valor superior (buffer) en la minima posicion alcanzada hasta encontrar uno menor
            strcpy(arrayY[j + 1],buffer2);
            arrayInt[j + 1]=buffer3;
        }
        retorno=0;
    }
    return retorno;
}


