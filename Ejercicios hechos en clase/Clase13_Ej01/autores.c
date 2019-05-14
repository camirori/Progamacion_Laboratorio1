#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autores.h"


/*
-Inicializar
-Buscar
    Empty
    ID
    Int
    String
-Alta
-Baja
    Valor unico
    Valor repetido
-Modificar
-Ordenar
-Listar
*/


//***************************************************************
//Init
/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array Tipo Array of Tipo
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int Autores_inicializar(Autores array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Autores_buscarEmpty(Autores array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Autores_buscarID(Autores array[], int size, int valosBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valosBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int Autores_buscarInt(Autores array[], int size, int valosBuscado, int* posicion)                    //cambiar Tipo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valosBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int Tipo_buscarString(Tipo array[], int size, char* valorBuscado, int* indice)                    //cambiar Tipo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
*/
//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Autores_alta(Autores array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Autores_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Tipo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            printf("\n Posicion: %d\n Codigo autor: %d\n Apellido: %s\n Nombre: %s",
                   posicion, array[posicion].idUnico,array[posicion].apellido,array[posicion].nombre);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Autores_baja(Autores array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nCodigo autor a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(Autores_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este Codigo de autor");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            strcpy(array[posicion].apellido,"");
            strcpy(array[posicion].nombre,"");
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
/*
int Tipo_bajaValorRepetidoInt(Tipo array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}
*/


//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int Autores_modificar(Autores array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nCodigo de autor a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(Autores_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Codigo de autor: %d\n Apellido: %s\n Nombre: %s",array[posicion].idUnico,array[posicion].apellido,array[posicion].nombre);
                utn_getLetra("\nModificar: A B C D S(salir)","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
                        break;
                    case 'B':
                        utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;

                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int Autores_ordenarPorApellido(Autores array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferApellido[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;
    char bufferNombre[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferApellido,array[i].apellido);
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;
            strcpy(bufferNombre,array[i].nombre);


            j = i - 1;
            while ((j >= 0) && (strcmp(bufferApellido,array[j].apellido)<0 || (strcmp(bufferApellido,array[j].apellido)==0 && strcmp(bufferNombre,array[j].nombre)==0)))
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].apellido,array[j].apellido);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].nombre,array[j].nombre);

                j--;
            }
            strcpy(array[j + 1].apellido,bufferApellido);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
            strcpy(array[j + 1].nombre,bufferNombre);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Autores_listar(Autores array[], int size)
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
                printf("\n Codigo de autor: %d\n Apellido: %s\n Nombre: %s",array[i].idUnico,array[i].apellido,array[i].nombre);

        }
        retorno=0;
    }
    return retorno;
}

