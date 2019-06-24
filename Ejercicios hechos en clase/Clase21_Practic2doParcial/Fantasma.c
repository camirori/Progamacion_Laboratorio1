#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Fantasma.h"       //Replace Fantasma (tipo) y entidad (f)
#include "utn.h"

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
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Fantasma*
 *
 */
Fantasma* entidad_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Fantasma* retorno=NULL;
    Fantasma* bufferP;

    if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        bufferP=entidad_new();
        if(bufferP!=NULL)
        {
            if(!entidad_setIdStr(bufferP,idStr) &&
                !entidad_setNombre(bufferP,nombreStr) &&
                !entidad_setHorasTrabajadasStr(bufferP,horasTrabajadasStr) &&
                !entidad_setSueldoStr(bufferP,sueldoStr))
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
 * \param empleado Fantasma
 * \return Fantasma*
 *
 */
Fantasma* entidad_newBinario(Fantasma empleado)
{
    Fantasma* retorno=NULL;
    Fantasma* bufferP;

    char arrayBuffers[3][STR_SIZE];

    sprintf(arrayBuffers[0],"%d",empleado.id);
    sprintf(arrayBuffers[1],"%d",empleado.horasTrabajadas);
    sprintf(arrayBuffers[2],"%d",empleado.sueldo);

    if(arrayBuffers[0]!=NULL && empleado.nombre!=NULL && arrayBuffers[1]!=NULL && arrayBuffers[2]!=NULL)
    {
        bufferP=entidad_new();
        if(bufferP!=NULL)
        {
            if(!entidad_setIdStr(bufferP,arrayBuffers[0]) &&
                !entidad_setNombre(bufferP,empleado.nombre) &&
                !entidad_setHorasTrabajadasStr(bufferP,arrayBuffers[1]) &&
                !entidad_setSueldoStr(bufferP,arrayBuffers[2]))
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

/** \brief Libera el espacio reservado en memoria para un empleado
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
 * \param horasTrabajadas char*
 * \return int
 *
 */
int entidad_setHorasTrabajadasStr(Fantasma* this,char* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL && isValidNumber(horasTrabajadas))
    {
        retorno=entidad_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param horasTrabajadas int
 * \return int
 *
 */
int entidad_setHorasTrabajadas(Fantasma* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Fantasma
 *
 * \param this Fantasma*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int entidad_getHorasTrabajadas(Fantasma* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param sueldo char*
 * \return int
 *
 */
int entidad_setSueldoStr(Fantasma* this,char* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL && isValidNumber(sueldo))
    {
        retorno=entidad_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Fantasma
 *
 * \param this Fantasma*
 * \param sueldo int
 * \return int
 *
 */
int entidad_setSueldo(Fantasma* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Fantasma
 *
 * \param this Fantasma*
 * \param sueldo int*
 * \return int
 *
 */
int entidad_getSueldo(Fantasma* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
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
