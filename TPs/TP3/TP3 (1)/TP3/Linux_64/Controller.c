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
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura

        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                parser_EmployeeFromText(pFile,pArrayListEmployee);
            }
            fclose(pFile);
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

    FILE *pFile=NULL;
    pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura
    Employee auxEmpleado;
    Employee* pEmpleado;

    if(pFile!=NULL)
    {
        while(!feof(pFile))                                         //armar un constructor que reciba como param un empleado
        {
            fread(&auxEmpleado,sizeof(Employee),1,pFile);
            printf("\n%d", auxEmpleado.id);
            pEmpleado=employee_new();
            if(!employee_setId(pEmpleado,auxEmpleado.id) &&
                !employee_setNombre(pEmpleado,auxEmpleado.nombre) &&
                !employee_setHorasTrabajadas(pEmpleado,auxEmpleado.horasTrabajadas) &&
                !employee_setSueldo(pEmpleado,auxEmpleado.sueldo))
            {
                ll_add(pArrayListEmployee,pEmpleado);
            }
            else
                employee_delete(pEmpleado);

        }
        fclose(pFile);
    }
    //si se logro cargar todos los datos del archivo retorno=0
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)       //en lugar de param, dentro de la funcion se tiene que llamar a buscarUltimoId()
{
    int retorno=-1;
    char arrayBuffers[4][STR_SIZE];
    Employee* auxPuntero=NULL;
    int ultimoId=0;

    if(pArrayListEmployee!=NULL)
    {
        employee_searchMaxId(pArrayListEmployee,&ultimoId);                                        //puedo ordenar por ID y obtener el ID del ultimo elemento???
        ultimoId++;
        utn_getTexto("\nNombre ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nHoras Trabajadas ","\nError",1,STR_SIZE,1,arrayBuffers[2]);
        utn_getTexto("\nSueldo ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",ultimoId);                                 //SIZE????

        auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
        if(auxPuntero!=NULL)
        {
            ll_add(pArrayListEmployee,auxPuntero);
            retorno=0;
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
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,&id);
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
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id);
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
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                fscanf(pFile,"%d",&pEmpleado->id);
                fwrite(pEmpleado,sizeof(Employee),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion

            }
            retorno=0;
            fclose(pFile);
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
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                fprintf(pFile,"\n%d",pEmpleado->id);
                fwrite(pEmpleado,sizeof(Employee),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion

            }
            retorno=0;
            fclose(pFile);
        }
    }
    return retorno;
}

