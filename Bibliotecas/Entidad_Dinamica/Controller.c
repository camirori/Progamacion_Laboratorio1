#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Fantasma.h"                          //Replace Fantasma (tipo) y entidad (f)     campos: Int1 + int1 // Int2 + int2 // Nombre2 + nombre2
#include "File.h"
#include "utn.h"


/*
Modificar
    Add: mensajes y buffers por campo
    Edit: buffers por campo, mensajes, funciones set en switch
    List: buffers y mensaje
    SaveAsText: buffers y mensaje

*/

/** \brief Carga los datos de los empleados desde el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 */
int controllerFantasma_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno=-1;
    int contadorError=0;
    int contadorCargados=0;
    int retornoParser;
    int option=0;

    FILE *pFile=NULL;

    utn_getUnsignedInt("\n\nSe reiniciara la lista con los elementos cargados desde el archivo. Desea continuar? \n1) Si 2) No ","\nError",1,2,1,&option);
    if(option==1)
    {
        if(path!=NULL && pArrayList!=NULL)
        {
            ll_clear(pArrayList);
            pFile=fopen(path,"r");    //direccion archivo, modo de arpetura

            if(pFile!=NULL)
            {
                while(!feof(pFile))
                {
                    retornoParser=parser_FantasmaFromText(pFile,pArrayList);
                    if(retornoParser==-2)
                        contadorError++;
                    else if(retornoParser==1)
                        contadorCargados++;
                }
                fclose(pFile);
                printf("\nError de validacion en %d elementos \n%d elementos cargados exitosamente",contadorError,contadorCargados);
                if(contadorCargados>0)
                    retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo indicado (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 */
int controllerFantasma_loadFromBinary(char* path , LinkedList* pArrayList)
{
    int retorno=-1;
    int contadorError=0;
    int contadorCargados=0;
    int retornoParser;
    int option=0;

    FILE *pFile=NULL;
    utn_getUnsignedInt("\n\nSe reiniciara la lista con los elementos cargados desde el archivo. Desea continuar? \n1) Si 2) No ","\nError",1,2,1,&option);
    if(option==1)
    {
        if(path!=NULL && pArrayList!=NULL)
        {
            ll_clear(pArrayList);
            pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura

            if(pFile!=NULL)
            {
                while(!feof(pFile))
                {
                    retornoParser=parser_FantasmaFromBinary(pFile,pArrayList);
                    if(retornoParser==-2)
                        contadorError++;
                    else if(retornoParser==0)
                        contadorCargados++;
                }
                fclose(pFile);
                printf("\nError de validacion en %d elementos \n%d elementos cargados exitosamente",contadorError,contadorCargados);
                if(contadorCargados>0)
                    retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Alta de Fantasma
 *
 * \param pArrayList LinkedList*
 * \param ultimoId int* Puntero al maximo ID actual de la lista
 * \return int -1 Error / 0 Alta exitosa
 *
 */
int controllerFantasma_addFantasma(LinkedList* pArrayList, int* ultimoId)
{
    int retorno=-1;
    char arrayBuffers[5][STR_SIZE];             //cambiar por cantidad de campos
    Fantasma* pFantasma=NULL;

    if(pArrayList!=NULL)
    {
        utn_getTexto("\nNombre ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nInt1","\nError",1,STR_SIZE,1,arrayBuffers[2]);           //cambiar
        utn_getTexto("\nInt2 ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",(*ultimoId)+1);

        pFantasma=entidad_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3],arrayBuffers[4]);         //valido los datos y lo guardo en aux
        if(pFantasma!=NULL)
        {
            ll_add(pArrayList,pFantasma);
            retorno=0;
            (*ultimoId)++;
            printf("\nAlta exitosa");
        }
        else
            printf("\nError");
    }
    return retorno;
}

/** \brief Modificar datos de Fantasma
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Modificacion exitosa
 *
 */
int controllerFantasma_editFantasma(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    char opcion;
    char bufferModificacion[STR_SIZE];
    int bufferID;
    int bufferInt1;                        //cambiar
    int bufferInt2;                       //cambiar
    char bufferNombre[STR_SIZE];
    char bufferNombre2[STR_SIZE];
    Fantasma* pFantasma=NULL;

    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a modificar: ","\nError",1,8,1,&id)==0)
        {
            if(entidad_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                do
                {
                    pFantasma=ll_get(pArrayList,indice);
                    entidad_getId(pFantasma,&bufferID);
                    entidad_getNombre(pFantasma,bufferNombre);
                    entidad_getNombre2(pFantasma,bufferNombre2);
                    entidad_getInt1(pFantasma,&bufferInt1);
                    entidad_getInt2(pFantasma,&bufferInt2);
                    printf("\n ID: %d   Nombre: %s   Nombre2: %s  Int1: %d   Int2: %d",bufferID,bufferNombre,bufferNombre2,bufferInt1,bufferInt2);                       //cambiar

                    utn_getLetra("\nModificar: A Nombre B Int1 C Int2 S(salir)","\nError",1,&opcion);                      //cambiar
                    switch(opcion)
                    {
                        case 'A':
                            utn_getTexto("\nNombre: ","\nError",1,STR_SIZE,1,bufferModificacion);                     //cambiar
                            entidad_setNombre(pFantasma,bufferModificacion);
                            break;
                        case 'B':
                            utn_getTexto("\n: ","\nError",1,sizeof(int),1,bufferModificacion);                       //cambiar
                            entidad_setInt1Str(pFantasma,bufferModificacion);
                            break;
                        case 'C':
                            utn_getTexto("\n: ","\nError",1,sizeof(int),1,bufferModificacion);                       //cambiar
                            entidad_setInt2Str(pFantasma,bufferModificacion);
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

/** \brief Baja de Fantasma
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Baja exitosa
 *
 */
int controllerFantasma_removeFantasma(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a cancelar: ","\nError",1,8,1,&id)==0)
        {
            if(entidad_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                ll_remove(pArrayList,indice);
                printf("\nBaja exitosa");
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Listar Fantasma
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerFantasma_ListFantasma(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferInt1;                       //cambiar
    int bufferInt2;
    char bufferNombre[STR_SIZE];
    char bufferNombre2[STR_SIZE];
    int size=ll_len(pArrayList);
    Fantasma* pFantasma;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            pFantasma=ll_get(pArrayList,i);
            entidad_getId(pFantasma,&bufferID);
            entidad_getNombre(pFantasma,bufferNombre);
            entidad_getNombre2(pFantasma,bufferNombre);
            entidad_getInt1(pFantasma,&bufferInt1);                       //cambiar
            entidad_getInt2(pFantasma,&bufferInt2);

            printf("\n ID: %d   Nombre: %s   Nombre2: %s  Int1: %d   Int2: %d",bufferID,bufferNombre,bufferNombre2,bufferInt1,bufferInt2);                       //cambiar
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena Fantasma por nombre (diferencia mayusculas y minusculas)
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerFantasma_sortFantasma(LinkedList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        ll_sort(pArrayList,entidad_cmpName,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 */
int controllerFantasma_saveAsText(char* path , LinkedList* pArrayList)
{
    int i;
    Fantasma* pFantasma=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    int bufferInt1;                       //cambiar
    int bufferInt2;                       //cambiar
    char bufferNombre[STR_SIZE];
    int contador=0;

    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pFantasma=ll_get(pArrayList,i);
                entidad_getId(pFantasma,&bufferID);
                entidad_getNombre(pFantasma,bufferNombre);
                entidad_getInt1(pFantasma,&bufferInt1);                       //cambiar
                entidad_getInt2(pFantasma,&bufferInt2);                       //cambiar

                if(fprintf(pFile,"%d,%s,%d,%d\n",bufferID,bufferNombre,bufferInt1,bufferInt2)>8)                       //cambiar
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los Fantasma en el archivo indicado (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 */
int controllerFantasma_saveAsBinary(char* path , LinkedList* pArrayList)
{
    int i;
    Fantasma* pFantasma=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int contador=0;
    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pFantasma=ll_get(pArrayList,i);         //obtengo el puntero de c/empleado
                contador+=fwrite(pFantasma,sizeof(Fantasma),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

