#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "utn.h"


Employee* employee_new(void)       //constructor         //nuevo empleado
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* retorno=NULL;
    Employee* bufferP;


    if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        bufferP=employee_new();
        if(bufferP!=NULL)
        {
            if(!employee_setIdStr(bufferP,idStr) &&
                !employee_setNombre(bufferP,nombreStr) &&
                !employee_setHorasTrabajadasStr(bufferP,horasTrabajadasStr) &&
                !employee_setSueldoStr(bufferP,sueldoStr))
            {
                retorno=bufferP;
            }
            else
            {
                employee_delete(bufferP);
            }
        }
    }
    return retorno;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//********************************************************************************************************************
//Setter+getters

int employee_setIdStr(Employee* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=employee_setId(this,atoi(id));
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}


int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL && isValidNumber(horasTrabajadas))
    {
        retorno=employee_setId(this,atoi(horasTrabajadas));
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL && isValidNumber(sueldo))
    {
        retorno=employee_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}


