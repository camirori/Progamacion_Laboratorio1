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
    int contadorError=0;
    int contadorCargados=0;
    int retornoParser;
    int option=0;

    FILE *pFile=NULL;

    utn_getUnsignedInt("\n\nSe reiniciara la lista con los elementos cargados desde el archivo. Desea continuar? \n1) Si 2) No","\nError",1,2,1,&option);
    if(option==1)
    {
        if(path!=NULL && pArrayListEmployee!=NULL)
        {
            ll_clear(pArrayListEmployee);
            pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura

            if(pFile!=NULL)
            {
                while(!feof(pFile))
                {
                    retornoParser=parser_EmployeeFromText(pFile,pArrayListEmployee);
                    if(retornoParser==-2)
                        contadorError++;
                    else if(retornoParser==1)
                        contadorCargados++;
                }
                fclose(pFile);
                printf("\nError de validacion en %d elementos \n%d elementos cargados exitosamente",contadorError,contadorCargados);
            }
        }
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
    int retorno=-1;
    int contadorError=0;
    int contadorCargados=0;
    int retornoParser;
    int option=0;

    FILE *pFile=NULL;
    utn_getUnsignedInt("\n\nSe reiniciara la lista con los elementos cargados desde el archivo. Desea continuar? \n1) Si 2) No","\nError",1,2,1,&option);
    if(option==1)
    {
        if(path!=NULL && pArrayListEmployee!=NULL)
        {
            ll_clear(pArrayListEmployee);
            pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura

            if(pFile!=NULL)
            {
                while(!feof(pFile))                                        //armar un constructor que reciba como param un empleado
                {
                    retornoParser=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
                    if(retornoParser==-2)
                        contadorError++;
                    else if(retornoParser==0)
                        contadorCargados++;
                }
                fclose(pFile);
                printf("\nError de validacion en %d elementos \n%d elementos cargados exitosamente",contadorError,contadorCargados);

            }
        }
    }
    return retorno;
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

    if(pArrayListEmployee!=NULL)
    {
        utn_getTexto("\nNombre ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nHoras Trabajadas ","\nError",1,STR_SIZE,1,arrayBuffers[2]);
        utn_getTexto("\nSueldo ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",(*ultimoId)+1);

        auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
        if(auxPuntero!=NULL)
        {
            ll_add(pArrayListEmployee,auxPuntero);
            retorno=0;
            (*ultimoId)++;
            printf("\nAlta exitosa");
        }
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
    int retorno=-1;
    int id;
    int indice;
    char opcion;
    char bufferModificacion[STR_SIZE];
    int bufferID;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[STR_SIZE];
    Employee* puntero=NULL;

    if(pArrayListEmployee!=NULL)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,8,1,&id);
        if(employee_searchId(pArrayListEmployee,id,&indice)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                puntero=ll_get(pArrayListEmployee,indice);
                employee_getId(puntero,&bufferID);
                employee_getNombre(puntero,bufferNombre);
                employee_getHorasTrabajadas(puntero,&bufferHoras);
                employee_getSueldo(puntero,&bufferSueldo);

                printf("\n ID: %d   Nombre: %s  Horas: %d   Sueldo: %d",bufferID,bufferNombre,bufferHoras,bufferSueldo);


                utn_getLetra("\nModificar: A Nombre B Horas C Sueldo S(salir)","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nNombre: ","\nError",1,STR_SIZE,1,bufferModificacion);
                        employee_setNombre(puntero,bufferModificacion);
                        break;
                    case 'B':
                        utn_getTexto("\nHoras: ","\nError",1,sizeof(int),1,bufferModificacion);
                        employee_setHorasTrabajadasStr(puntero,bufferModificacion);
                        break;
                    case 'C':
                        utn_getTexto("\nSueldo: ","\nError",1,sizeof(int),1,bufferModificacion);
                        employee_setSueldoStr(puntero,bufferModificacion);
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

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int indice;
    if(pArrayListEmployee!=NULL)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,8,1,&id);
        if(employee_searchId(pArrayListEmployee,id,&indice)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListEmployee,indice);
            printf("\nBaja exitosa");
            retorno=0;
        }
    }
    return retorno;
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
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_cmpName,1);
        retorno=0;
    }
    return retorno;
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
    int i;
    Employee* pEmpleado=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[STR_SIZE];
    int contador=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                employee_getId(pEmpleado,&bufferID);
                employee_getNombre(pEmpleado,bufferNombre);
                employee_getHorasTrabajadas(pEmpleado,&bufferHoras);
                employee_getSueldo(pEmpleado,&bufferSueldo);

                if(fprintf(pFile,"%d,%s,%d,%d\n",bufferID,bufferNombre,bufferHoras,bufferSueldo)>8)
                    contador++;
                //fwrite(pEmpleado,sizeof(Employee),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
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
    int i;
    Employee* pEmpleado=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int contador=0;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);         //obtengo el puntero de c/empleado
                contador+=fwrite(pEmpleado,sizeof(Employee),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

