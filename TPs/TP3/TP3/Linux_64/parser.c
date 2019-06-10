#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* auxPuntero=NULL;
    char arrayBuffers[4][STR_SIZE];

    if(pFile!=NULL)
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3])==4)
            retorno=0;                                                                      //exit?
        if(strcmp(arrayBuffers[0],"id")==0)
            retorno=-1;                                     //exit?

        if(retorno==0)
        {
            auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
            if(auxPuntero!=NULL)
            {
                ll_add(pArrayListEmployee,auxPuntero);
                retorno=1;
                /*
                auxPuntero=ll_get(pArrayListEmployee,(pArrayListEmployee->size)-1);
                if(auxPuntero!=NULL)
                {
                    int bufferID;
                    int bufferHoras;
                    int bufferSueldo;
                    char bufferNombre[STR_SIZE];
                    employee_getId(auxPuntero,&bufferID);
                    employee_getNombre(auxPuntero,bufferNombre);
                    employee_getHorasTrabajadas(auxPuntero,&bufferHoras);
                    employee_getSueldo(auxPuntero,&bufferSueldo);
                    printf("\n ID: %d Nombre: %s Horas: %d Sueldo: %d",bufferID,bufferNombre,bufferHoras,bufferSueldo);

                }*/

            }
            else
            {
                //printf("\nError validacion");
                retorno=-2;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee auxEmpleado;
    Employee* pEmpleado;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fread(&auxEmpleado,sizeof(Employee),1,pFile);
        pEmpleado=employee_newBinario(auxEmpleado);

        if(pEmpleado!=NULL)
        {
            ll_add(pArrayListEmployee,pEmpleado);
            printf("\n%d", pEmpleado->id);
            retorno=0;
        }
        else
        {
            employee_delete(pEmpleado);
            retorno=-2;
        }
    }
    return retorno;
}

