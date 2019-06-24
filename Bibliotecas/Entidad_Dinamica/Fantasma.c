#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Fantasma.h"       //Replace Fantasma (tipo) y entidad (f)     campos: Int1 + int1 // Int2 + int2 // Nombre2 + nombre2
#include "utn.h"


/*
-entidad_new
-entidad_newParametros          //cambiar campos
-entidad_newBinario             //cambiar campos
-entidad_delete

-entidad_setIdStr
-entidad_setId
-entidad_getId

-entidad_setNombre
-entidad_getNombre

-entidad_setNombre2
-entidad_getNombre2

-entidad_setInt1Str
-entidad_setInt1
-entidad_getInt1

-entidad_setInt2Str
-entidad_setInt2
-entidad_getInt2

-entidad_cmpId
-entidad_cmpName

-entidad_searchId
-entidad_searchMaxId

*/

/** \brief Reserva espacio en memoria para un Fantasma
 *
 * \param void
 * \return Fantasma*
 *
 */
Fantasma* entidad_new(void)       //constructor         //nuevo Fantasma
{
    return (Fantasma*) malloc(sizeof(Fantasma));
}

/** \brief Valida los campos y los carga en una variable Fantasma
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param int1Str char*
 * \param int2Str char*
 * \return Fantasma*
 *
 */
Fantasma* entidad_newParametros(char* idStr,char* nombreStr,char* nombre2Str,char* int1Str, char* int2Str)
{
    Fantasma* retorno=NULL;
    Fantasma* bufferP;

    if(idStr!=NULL && nombreStr!=NULL && int1Str!=NULL && int2Str!=NULL)
    {
        bufferP=entidad_new();
        if(bufferP!=NULL)
        {
            if(!entidad_setIdStr(bufferP,idStr) &&
                !entidad_setNombre(bufferP,nombreStr) &&
                !entidad_setNombre2(bufferP,nombre2Str) &&
                !entidad_setInt1Str(bufferP,int1Str) &&
                !entidad_setInt2Str(bufferP,int2Str))
            {
                retorno=bufferP;
            }
            else
            {
                entidad_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Valida los campos y los carga en una variable Fantasma
 *
 * \param entidad Fantasma
 * \return Fantasma*
 *
 */
Fantasma* entidad_newBinario(Fantasma entidad)
{
    Fantasma* retorno=NULL;
    Fantasma* bufferP;

    char arrayBuffers[3][STR_SIZE];

    sprintf(arrayBuffers[0],"%d",entidad.id);
    sprintf(arrayBuffers[1],"%d",entidad.int1);
    sprintf(arrayBuffers[2],"%d",entidad.int2);

    if(arrayBuffers[0]!=NULL && entidad.nombre!=NULL && arrayBuffers[1]!=NULL && arrayBuffers[2]!=NULL)
    {
        bufferP=entidad_new();
        if(bufferP!=NULL)
        {
            if(!entidad_setIdStr(bufferP,arrayBuffers[0]) &&
                !entidad_setNombre(bufferP,entidad.nombre) &&
                !entidad_setNombre(bufferP,entidad.nombre2) &&
                !entidad_setInt1Str(bufferP,arrayBuffers[1]) &&
                !entidad_setInt2Str(bufferP,arrayBuffers[2]))
            {
                retorno=bufferP;
            }
            else
            {
                entidad_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para un entidad
 *
 * \param this Fantasma*
 * \return void
 *
 */
void entidad_delete(Fantasma* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//********************************************************************************************************************
//Setter+getters


/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param id char*
 * \return int
 *
 */
int entidad_setIdStr(Fantasma* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=entidad_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param id int
 * \return int
 *
 */
int entidad_setId(Fantasma* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Fantasma
 *
 * \param this Fantasma*
 * \param id int*
 * \return int
 *
 */
int entidad_getId(Fantasma* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param nombre char*
 * \return int
 *
 */
int entidad_setNombre(Fantasma* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Fantasma
 *
 * \param this Fantasma*
 * \param nombre char*
 * \return int
 *
 */
int entidad_getNombre(Fantasma* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param nombre2 char*
 * \return int
 *
 */
int entidad_setNombre2(Fantasma* this,char* nombre2)
{
    int retorno=-1;
    if(this!=NULL && nombre2!=NULL && isValidName(nombre2))
    {
        strcpy(this->nombre2,nombre2);
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Fantasma
 *
 * \param this Fantasma*
 * \param nombre2 char*
 * \return int
 *
 */
int entidad_getNombre2(Fantasma* this,char* nombre2)
{
    int retorno=-1;
    if(this!=NULL && nombre2!=NULL)
    {
        strcpy(nombre2,this->nombre2);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param int1 char*
 * \return int
 *
 */
int entidad_setInt1Str(Fantasma* this,char* int1)
{
    int retorno=-1;
    if(this!=NULL && int1!=NULL && isValidNumber(int1))
    {
        retorno=entidad_setInt1(this,atoi(int1));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param int1 int
 * \return int
 *
 */
int entidad_setInt1(Fantasma* this,int int1)
{
    int retorno=-1;
    if(this!=NULL && int1>=0)
    {
        this->int1=int1;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Fantasma
 *
 * \param this Fantasma*
 * \param int1 int*
 * \return int
 *
 */
int entidad_getInt1(Fantasma* this,int* int1)
{
    int retorno=-1;
    if(this!=NULL && int1!=NULL)
    {
        *int1=this->int1;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param int2 char*
 * \return int
 *
 */
int entidad_setInt2Str(Fantasma* this,char* int2)
{
    int retorno=-1;
    if(this!=NULL && int2!=NULL && isValidNumber(int2))
    {
        retorno=entidad_setInt2(this,atoi(int2));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param int2 int
 * \return int
 *
 */
int entidad_setInt2(Fantasma* this,int int2)
{
    int retorno=-1;
    if(this!=NULL && int2>=0)
    {
        this->int2=int2;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Fantasma
 *
 * \param this Fantasma*
 * \param int2 int*
 * \return int
 *
 */
int entidad_getInt2(Fantasma* this,int* int2)
{
    int retorno=-1;
    if(this!=NULL && int2!=NULL)
    {
        *int2=this->int2;
        retorno=0;
    }
    return retorno;
}

//*******************************************************************

/** \brief Busca un ID y devuelve el indice
 *
 * \param pArrayList LinkedList*
 * \param valorBuscado int
 * \param index int*
 * \return int
 *
 */
int entidad_searchId(LinkedList* pArrayList, int valorBuscado, int* index)
{
    int retorno=-1;
    int i;
    int bufferID;
    int size=ll_len(pArrayList);
    Fantasma* puntero=NULL;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            entidad_getId(puntero,&bufferID);

            if(valorBuscado==bufferID)
            {
                *index=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Compara dos ID
 *
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
int entidad_cmpId(void* this1, void* this2)
{
    int retorno=-1;

    int bufferIdI;
    int bufferIdJ;

    if(this1!=NULL && this2!=NULL)
    {
        entidad_getId((Fantasma*)this1,&bufferIdI);
        entidad_getId((Fantasma*)this2,&bufferIdJ);
        if(bufferIdI==bufferIdJ)
            retorno=0;
        else if(bufferIdI>bufferIdJ)
            retorno=1;
        else if(bufferIdI<bufferIdJ)
            retorno=-1;
    }
    return retorno;
}

/** \brief Compara dos Nombres
 *
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
int entidad_cmpName(void* this1, void* this2)          //el sort es generico asique se usa el puntero generico void
{
    int retorno=-1;

    char bufferI[STR_SIZE];
    char bufferJ[STR_SIZE];

    if(this1!=NULL && this2!=NULL)
    {
        entidad_getNombre((Fantasma*)this1,bufferI);
        entidad_getNombre((Fantasma*)this2,bufferJ);
        if(strcmp(bufferI,bufferJ)==0)
            retorno=0;
        if(strcmp(bufferI,bufferJ)>0)
            retorno=1;
        if(strcmp(bufferI,bufferJ)<0)
            retorno=-1;
    }
    return retorno;
}

/** \brief Busca el maximo ID
 *
 * \param pArrayList LinkedList*
 * \param maxID int*
 * \return int
 *
 */
int entidad_searchMaxId(LinkedList* pArrayList, int* maxID)
{
    int retorno=-1;
    Fantasma* puntero=NULL;
    int size=ll_len(pArrayList);
    int i;
    int bufferId;
    int bufferMaxId=*maxID;

    if(pArrayList!=NULL && maxID!=NULL)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            if(puntero!=NULL)
            {
                entidad_getId(puntero,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        retorno=0;
    }
    return retorno;
}
