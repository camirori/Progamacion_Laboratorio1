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
            retorno=1;                                                                      //exit?
        if(strcmp(arrayBuffers[0],"id")==0)
            retorno=-1;                                     //exit?

        if(retorno==1)
        {
            auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
            if(auxPuntero!=NULL)
            {
                    //(*index)++;
                        //pArrayListEmployee.pFirstNode.pElement=auxPuntero;             //paso a la lista de punteros &nueva persona           get nçNode???

                ll_add(pArrayListEmployee,auxPuntero);
                auxPuntero=ll_get(pArrayListEmployee,pArrayListEmployee->size);

                            printf("a");

                if(auxPuntero!=NULL)
                {
                                                                printf("a");

                    int bufferID;
                    int bufferHoras;
                    int bufferSueldo;
                    char bufferNombre[STR_SIZE];
                    employee_getId(auxPuntero,&bufferID);
                    employee_getNombre(auxPuntero,bufferNombre);
                    employee_getHorasTrabajadas(auxPuntero,&bufferHoras);
                    employee_getSueldo(auxPuntero,&bufferSueldo);
                    printf("\n ID: %d\n Nombre: %s\n Horas: %d\n Sueldo: %d",bufferID,bufferNombre,bufferHoras,bufferSueldo);
                    //(pArrayListEmployee->size)++;
                    retorno=0;
                }

                        //*ultimoId=(*(pLista+*index))->id;
            }
            else
                printf("\nError validacion");
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

    return 1;
}

