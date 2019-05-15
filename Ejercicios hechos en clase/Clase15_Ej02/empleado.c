#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "utn.h"



Empleado* Emp_new(void)       //constructor
{
    return (Empleado*) malloc(sizeof(Empleado));
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

int Emp_getId(Empleado* this, int* resultado)       //para traer/consultar
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->id;
        retorno=0;
    }
    return retorno;
}

//las -> van a estar unicamente en los set y get


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
}

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

int Emp_setEstado(Empleado* this, int estado)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->estado=estado;
        retorno=0;
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
}

int Emp_nuevoEmpleado(Empleado* pEmpleado[], int* indice)
{
    int retorno=-1;
    if(pEmpleado!=NULL)
    {
        int indiceActual=*indice;

        Emp_new();
        (*indice)++;
        printf("Ok\n");

        if( !Emp_setId(pEmpleado[indiceActual],14) && !Emp_setPeso(pEmpleado[indiceActual],50) &&
            !Emp_setNombre(pEmpleado[indiceActual],"abc") && !Emp_setId(pEmpleado[indiceActual],1))     //==0   //set>escribe un campo de empleado
            retorno=0;
    }
    return retorno;
}
