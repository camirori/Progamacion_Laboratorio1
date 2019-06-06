#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    FILE *pFile=NULL;
    //FILE *pFileBkp=NULL;
    pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura
    //pFileBkp=fopen("data_bkp.csv","w");     //???

    if(pFile!=NULL)
    {

        while(!feof(pFile))
        {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        fclose(pFile);
        //fclose(pFileBkp);
    }
    //si se logro cargar todos los datos del archivo retorno=0
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* ultimoId)       //en lugar de param, dentro de la funcion se tiene que llamar a buscarUltimoId()
{
    int retorno=-1;
    char arrayBuffers[4][STR_SIZE];
    Employee* auxPuntero=NULL;
    //int ultimoId;

    if(pArrayListEmployee!=NULL)
    {
                                                //puedo ordenar por ID y obtener el ID del ultimo elemento???
        (*ultimoId)++;
        utn_getTexto("\nNombre ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nHoras Trabajadas ","\nError",1,STR_SIZE,1,arrayBuffers[2]);
        utn_getTexto("\nSueldo ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",*ultimoId);                                 //SIZE????

        auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
        if(auxPuntero!=NULL)
        {
            ll_add(pArrayListEmployee,auxPuntero);
            retorno=0;
            printf("\nAlta exitosa");
        }
        else
            (*ultimoId)--;
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[STR_SIZE];
    int size=ll_len(pArrayListEmployee);
    Employee* puntero;

    if(pArrayListEmployee!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayListEmployee,i);
            employee_getId(puntero,&bufferID);
            employee_getNombre(puntero,bufferNombre);
            employee_getHorasTrabajadas(puntero,&bufferHoras);
            employee_getSueldo(puntero,&bufferSueldo);

            printf("\n ID: %d   Nombre: %s  Horas: %d   Sueldo: %d",bufferID,bufferNombre,bufferHoras,bufferSueldo);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

