#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Fantasma.h"      //Replace Fantasma (tipo) y entidad (f)

/*
Cambiar
    cantidad de buffers, cantidad de elementos en mascara
*/

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FantasmaFromText(FILE* pFile , LinkedList* pArrayList)
{
    int retorno=-1;
    Fantasma* auxPuntero=NULL;
    char arrayBuffers[4][STR_SIZE];                                     //cambiar

    if(pFile!=NULL)
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3])==4)       //cambiar
            retorno=0;
        if(strcmp(arrayBuffers[0],"id")==0)
            retorno=-1;

        if(retorno==0)
        {                                                                                                                       //cambiar
            auxPuntero=entidad_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3],arrayBuffers[4]);         //valido los datos y lo guardo en aux
            if(auxPuntero!=NULL)
            {
                ll_add(pArrayList,auxPuntero);
                retorno=1;
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FantasmaFromBinary(FILE* pFile , LinkedList* pArrayList)
{
    int retorno=-1;
    Fantasma auxFantasma;
    Fantasma* pFantasma;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        if(fread(&auxFantasma,sizeof(Fantasma),1,pFile)==1)
        {
            pFantasma=entidad_newBinario(auxFantasma);
            if(pFantasma!=NULL)
            {
                ll_add(pArrayList,pFantasma);
                //printf("\n%d", pFantasma->id);
                retorno=0;
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}
