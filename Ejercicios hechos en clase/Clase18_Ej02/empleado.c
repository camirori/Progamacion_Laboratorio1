#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "utn.h"



Empleado* Emp_new(void)       //constructor         //nuevo empleado
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* Emp_newStr(char *id, char *nombre, char *apellido, char *estado)       //constructor         //nuevo empleado con los campos cargados
{
    Empleado* retorno=NULL;
    Empleado* bufferP;
    if(id!=NULL && nombre!=NULL && apellido!=NULL && estado!=NULL)
    {
        bufferP=Emp_new();
        if(bufferP!=NULL)
        {
            printf("\nOk4");

            if(!Emp_setIdStr(bufferP,id) &&                 //puedo poner retorno=-1,-2,-3 etc para saber cual es el param fuera de rango
                !Emp_setNombre(bufferP,nombre) &&
                !Emp_setApellido(bufferP,apellido) &&
                !Emp_setEstadoStr(bufferP,estado))
            {
                retorno=bufferP;

            }
            /*
            if(!Emp_setNombre(bufferP,nombre))
            {
                printf("\nOk5");
                if(!Emp_setApellido(bufferP,apellido))
                {
                   printf("\nOk6");
                   if(!Emp_setEstadoStr(bufferP,estado))
                   {
                       printf("\nOk7");
                       if(!Emp_setIdStr(bufferP,id))
                            printf("\nOk8");
                            printf("\nId: %d    Nombre: %s  Apellido: %s  Estado: %s",bufferP->id,bufferP->nombre,bufferP->apellido,bufferP->estado);
                            retorno=bufferP;
                   }
                }
            }*/
            else
            {
                Emp_delete(bufferP);
                //realloc array punteros tmb
            }
        }
    }
    return retorno;
}


Empleado** Emp_newPointer(Empleado** pPuntero, int i)       //constructor       //nuevo puntero a empleado
{
    if(i==1)
        return (Empleado**) malloc(i*sizeof(Empleado*));
    else
        return (Empleado**) realloc(pPuntero,i*sizeof(Empleado*));
}

int Emp_delete(Empleado* this)       //destructor
{
    int retorno=-1;
    if(this!=NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}

int Emp_deleteP(Empleado** this)       //destructor     //borro puntero
{
    int retorno=-1;
    if(this!=NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}

int Emp_setId(Empleado* this, int id)      //para escribir
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Emp_setIdStr(Empleado* this, char *id)      //siempre que el get original no sea char hay que hace un getStr
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=Emp_setId(this,atoi(id));
    }
    return retorno;
}


int Emp_getId(Empleado* this, int* resultado)       //para traer/consultar  int idAux=Emp_getId();
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->id;
        retorno=0;
    }
    return retorno;
}

int Emp_getIdStr(Empleado* this, char* resultado)       //trae el id y lo puedo transformar
{
    int retorno=-1;
    int bufferInt;
    if(this!=NULL && resultado!=NULL)
    {
        Emp_getId(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno=0;
    }
    return retorno;
}

//las -> van a estar unicamente en los set y get

/*
int Emp_setPeso(Empleado* this, float peso)
{
    int retorno=-1;
    if(this!=NULL && peso>=0)
    {
        utn_getFloat("\nPeso: ","\nError",1,3,1,&peso);

        this->peso=peso;
        retorno=0;
    }
    return retorno;
}

int Emp_getPeso(Empleado* this, float* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->peso;
        retorno=0;
    }
    return retorno;
}*/

int Emp_setNombre(Empleado* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {

        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Emp_getNombre(Empleado* this, char* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        strcpy(resultado,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Emp_setApellido(Empleado* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {

        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int Emp_getApellido(Empleado* this, char* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        strcpy(resultado,this->apellido);
        retorno=0;
    }
    return retorno;
}

/*
int Emp_setEstado(Empleado* this, int estado)       //transformo TRUE> 1
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->estado=estado;
        retorno=0;
    }
    return retorno;
}

int Emp_setEstadoStr(Empleado* this, char* estado)
{
    int retorno=-1;
    int bufferInt=0;
    if(this!=NULL && id!=NULL && !isValidNumber(id))
    {
        retorno=Emp_setId(this,atoi(id));
    }
    return retorno;
}


int Emp_getEstado(Empleado* this, int* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->estado;
        retorno=0;
    }
    return retorno;
}*/

int Emp_setEstadoStr(Empleado* this, char* estado)
{
    int retorno=-1;
    if(this!=NULL && estado!=NULL)
    {
        strcpy(this->estado,estado);
        retorno=0;
    }
    return retorno;
}
