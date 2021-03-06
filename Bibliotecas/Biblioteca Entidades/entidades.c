#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "entidades.h"  //cambiar por nombre entidad


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
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Tipo Array of Tipo
* \param size int Array length
* \return int Return (-1) si Error [tama�o invalido o NULL pointer] - (0) si Ok
*
*/
int Tipo_Inicializar(Tipo array[], int size)                                    //cambiar Tipo
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
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Tipo_buscarEmpty(Tipo array[], int size, int* posicion)                    //cambiar Tipo
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
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Tipo_buscarID(Tipo array[], int size, int valosBuscado, int* posicion)                    //cambiar Tipo
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
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Tipo_buscarInt(Tipo array[], int size, int valosBuscado, int* posicion)                    //cambiar Tipo
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

//String
/** \brief Busca un string en un array
* \param array Tipo Array de Tipo
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
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

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Tipo Array de Tipo
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Tipo_alta(Tipo array[], int size, int* contadorID)                          //cambiar Tipo
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Tipo_buscarEmpty(array,size,&posicion)==-1)                          //cambiar Tipo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&array[posicion].varInt) == 0 &&               //mensaje + cambiar campo varInt
                utn_getFloat("\n: ","\nError",1,sizeof(float),1,&array[posicion].varFloat) == 0 &&              //mensaje + cambiar campo varFloat
                utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString) == 0 &&                      //mensaje + cambiar campo varString
                utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString) == 0)                 //mensaje + cambiar campo varLongString
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;

                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}
/*
Si me pide que uno de los campos tiene que existir en otro array sumo en parametros ese otro array y el tama�o
int posicion(no se usa)
en la validacion (if) sumo Tipo_getInt/String/ID()!=-1 >> !=-1 significa que encontr� ese valor
agregar la entidad en define en el c y h
*/

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Tipo Array de Tipo
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Tipo_baja(Tipo array[], int sizeArray)                                      //cambiar Tipo
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        if(utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id)==0)         //cambiar si no se busca por ID
        {
            if(Tipo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                array[posicion].isEmpty=1;
                array[posicion].idUnico=0;                                                                   //cambiar campo id
                array[posicion].varInt=0;                                                               //cambiar campo varInt
                array[posicion].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
                strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
                retorno=0;
            }
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array Tipo Array de Tipo
* \param size int Tama�o del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
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



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Tipo Array de Tipo
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int Tipo_modificar(Tipo array[], int sizeArray)                                //cambiar Tipo
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        if(utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,&id)==0)         //cambiar si no se busca por ID
        {
            if(Tipo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
            }
            else
            {
                do
                {       //copiar printf de alta
                    printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                           posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                    utn_getLetra("\nModificar: A B C D S(salir)","\nError",1,&opcion);
                    switch(opcion)
                    {
                        case 'A':
                            utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                            break;
                        case 'B':
                            utn_getFloat("\n: ","\nError",1,sizeof(float),1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                            break;
                        case 'C':
                            utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                            break;
                        case 'D':
                            utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
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
    }
    return retorno;
}
/*
Si me pide que uno de los campos tiene que existir en otro array sumo en parametros ese otro array y el tama�o
int posicion(no se usa)
en la validacion (if) sumo Tipo_getInt/String/ID()!=-1 >> !=-1 significa que encontr� ese valor
agregar la entidad en define en el c y h


int buffer;
utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&buffer);
if(Tipo_buscarID(arrayAux,sizeAux,buffer,&bufferPos)!=-1)
    array[posicion].idArrayAux=buffer;
*/

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array Tipo Array de Tipo
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int Tipo_ordenarPorString(Tipo array[],int size)                              //cambiar Tipo
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            strcpy(bufferString,array[i].varString);                      //cambiar campo varString
            bufferInt=array[i].varInt;                                //cambiar campo varInt
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].varString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                strcpy(array[j + 1].varString,array[j].varString);          //cambiar campo varString

                array[j + 1].varInt=array[j].varInt;                        //cambiar campo varInt
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            strcpy(array[j + 1].varString,bufferString);                     //cambiar campo varString

            array[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Tipo Array de Tipo
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Tipo_listar(Tipo array[], int size)                      //cambiar Tipo
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
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

