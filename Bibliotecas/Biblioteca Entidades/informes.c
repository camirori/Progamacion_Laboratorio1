#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "entidades.h"  //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Tipo Array de Tipo
* \param arrayB Tipo Array de Tipo
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarPorCriterio(Tipo arrayA[], Tipo arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{                                                                                                   //La solicitud del valor a buscar/criterio lo puedo hacer antes del for en lugar de parametro
    int retorno=-1;
    int i;
    int j;
    int flag=-1;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        //puedo solicitar el criterio a comparar aca utn_getdato
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty!=1 && strcmp(arrayA[i].varString,criterio)==0)                 //cambiar campo donde busco el criterio
            {
                if(Tipo_buscarID(arrayB,sizeJ,arrayA[i].idUnico,&j)==-1)                 //cambiar Tipo, busco por el campo en comun
                    j=-1;                                                                  //para marcar si no se encontró campo camún
                if(j==-1)
                    printf(" ");
                else
                {
                    printf("\nID A: %d\nID B: %d",
                       arrayA[i].idUnico,arrayB[j].idUnico);
                }
                flag=0;
            }
        }
        if(flag==-1)
            printf("\nNo se han encontrado coincidencias");         //No se cumple el criterio o están todos vacios
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Tipo Array de Tipo
* \param arrayB Tipo Array de Tipo
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Cuenta las veces que se cumple un criterio en un arrayA y lo imprime una sola vez
int Informes_listarCriterioContadorAcumulado(Tipo arrayA[], int sizeI)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;
    int flag=-1;

    if(arrayA!=NULL && sizeI>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            Tipo_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty!=1 && auxPosicion==-1)                                                           //Si ese valor ya aparecio > continue
            {
                for(k=i,contador=0,acumulado=0;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].varString,arrayA[i].varString)==0)     //Busco las coincidencias en el 2do array
                    {
                        contador++;
                        acumulado+=(arrayA[k].varInt);
                        flag=0;
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
            }
        }
        if(flag==-1)
            printf("\n ");
        retorno=0;
    }
    return retorno;
}

//cuenta las ocurrencias de A en B
int Informes_ContadorAcumuladoOcurrencia(Tipo arrayA[], Tipo arrayB[], int sizeI, int sizeJ)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int acumulado=0;
    int flag=-1;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty!=1)                                                           //Si ese valor ya aparecio > continue
            {
                for(j=0,contador=0,acumulado=0;j<sizeJ;j++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].varInt)     //Busco todas las veces que aparece ese id
                    {
                        contador++;
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
            }
            if (contador<6)
            {
                //si se cumple alguna condicion de cantidad de veces
                flag=0;
            }
        }
        if(flag==-1)
            printf("\n ");
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Tipo Array de Tipo
* \param arrayB Tipo Array de Tipo
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_maxContadorAcumulado(Tipo arrayA[], Tipo arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int auxPosicion;
    //int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    //int iMaxAcumulado [sizeI];
    int iMaxContador [sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            //iMaxAcumulado[i]=-2;                        //Para marcar los lugares vacios
            iMaxContador[i]=-2;
            Tipo_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //si busco las coincidencias dentro del mismo array  en el for j=i
            if(arrayA[i].isEmpty==1 && auxPosicion==-1)
            {
                for(j=0,contador=0;j<sizeJ;j++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayB[j].isEmpty!=1 && arrayA[i].idUnico==arrayB[j].varInt)     //Busco campo en comun
                    {
                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayA[i].varInt*arrayB[j].varInt);
                    }
                }
                //Guardo los max acumulado y contador
                if(i==0)
                    maxContador=contador;
                else if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;

                contador=0;
            }
        }

        printf("\nMax: %d",maxContador);
        for(i--;iMaxContador[i]!=-1 && i>=0;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n ID: %d   : %s  : %d: ",
                       arrayA[iMaxContador[i]].idUnico,arrayA[iMaxContador[i]].varString,arrayA[iMaxContador[i]].varInt);
            }
        }

        retorno=0;
    }
    return retorno;
}

/** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Tipo Array de Tipo
* \param arrayB Tipo Array de Tipo
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarAuxiliarOrdenar(Tipo arrayA[], Tipo arrayB[], int sizeI, int sizeJ)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Tipo arrayAux[sizeI];                                                           //cambiar Tipo y size si corresponde

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            Tipo_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty!=1 && auxPosicion==-1)
            {
                strcpy(arrayAux[i].varString,arrayA[i].varString);                              //cambio varstring
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        Tipo_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Tipo, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].varInt*arrayB[j].varInt);

                    }
                }
                arrayAux[i].varInt=contador;                                    //completo el resto de los campos
                arrayAux[i].varInt=acumulado;
                arrayAux[i].isEmpty=0;

                contador=0;
                acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

