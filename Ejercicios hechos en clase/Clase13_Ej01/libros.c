#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libros.h"


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
int Libros_Inicializar(Libros array[], int size)
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
int Libros_buscarEmpty(Libros array[], int size, int* posicion)
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
int Libros_buscarID(Libros array[], int size, int valosBuscado, int* posicion)
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
int Libros_buscarInt(Libros array[], int size, int valosBuscado, int* posicion)                    //cambiar Tipo
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
int Libros_alta(Libros array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Libros_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Tipo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getTexto("\nTitulo: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);                 //mensaje + cambiar campo varLongString
            utn_getUnsignedInt("\nCodigo de autor: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idAutor);           //mensaje + cambiar campo varInt
            printf("\n Posicion: %d\n Codigo de libro: %d\n Titulo: %s\n Codigo de autor: %d",
                   posicion, array[posicion].idUnico,array[posicion].titulo,array[posicion].idAutor);
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
int Libros_baja(Libros array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nCodigo de libro a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(Libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este Codigo de libro");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].idAutor=0;                                                               //cambiar campo varInt
            strcpy(array[posicion].titulo,"");                                               //cambiar campo varLongString
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
int Libros_modificar(Libros array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nCodigo de libro a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(Libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este Codigo de libro");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Codigo de libro: %d\n Titulo: %s\n Codigo de autor: %d",
                    array[posicion].idUnico,array[posicion].titulo,array[posicion].idAutor);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("\nTitulo: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);                 //mensaje + cambiar campo varLongString
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nCodigo de autor: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idAutor);
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
int Libros_ordenarPorTitulo(Libros array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferTitulo[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;
    int bufferIdAutor;                                              //cambiar buffer int

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferTitulo,array[i].titulo);                      //cambiar campo varString
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;
            bufferIdAutor=array[i].idAutor;                                //cambiar campo varInt

            j = i - 1;
            while ((j >= 0) && strcmp(bufferTitulo,array[j].titulo)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].titulo,array[j].titulo);          //cambiar campo varString
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].idAutor=array[j].idAutor;                        //cambiar campo varInt

                j--;
            }
            strcpy(array[j + 1].titulo,bufferTitulo);                     //cambiar campo varString
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].idAutor=bufferIdAutor;                                                        //cambiar campo varInt
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
int Libros_listar(Libros array[], int size)
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
                printf("\n Codigo de libro: %d\n Titulo: %s\n Codigo de autor: %d",
                    array[i].idUnico,array[i].titulo,array[i].idAutor);     //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
