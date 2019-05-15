#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pEmpleado[1000];  //array punteros a empleado
    int ultimoElementoArrayEmpleado=0;

    int auxInt;
    float auxFloat;
    char auxChar[10];
    int auxEstado;

    /*
    int indiceActual=ultimoElementoArrayEmpleado;
    pEmpleado[indiceActual]=Emp_new();


    if(pEmpleado[indiceActual]!=NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("Ok\n");
        if( !Emp_setId(pEmpleado[indiceActual],14) && !Emp_setPeso(pEmpleado[indiceActual],50) &&
            !Emp_setNombre(pEmpleado[indiceActual],"abc") && !Emp_setId(pEmpleado[indiceActual],1))    //==0   //set>escribe un campo de empleado
        {
            Emp_getId(pEmpleado[indiceActual],&auxInt);
            Emp_getPeso(pEmpleado[indiceActual],&auxFloat);
            Emp_getNombre(pEmpleado[indiceActual],auxChar);
            Emp_getEstado(pEmpleado[indiceActual],&auxEstado);

            printf("\nEl ID es %d",auxInt);
            printf("\nEl peso es %.2f",auxFloat);
        }
    }*/

    if(pEmpleado[ultimoElementoArrayEmpleado]!=NULL)
    {
        if( !Emp_nuevoEmpleado(pEmpleado,&ultimoElementoArrayEmpleado))    //==0   //set>escribe un campo de empleado
        {
            Emp_getId(pEmpleado[ultimoElementoArrayEmpleado],&auxInt);
            Emp_getPeso(pEmpleado[ultimoElementoArrayEmpleado],&auxFloat);
            Emp_getNombre(pEmpleado[ultimoElementoArrayEmpleado],auxChar);
            Emp_getEstado(pEmpleado[ultimoElementoArrayEmpleado],&auxEstado);

            printf("\nEl ID es %d",auxInt);
            printf("\nEl peso es %.2f",auxFloat);
        }
    }



    return 0;
}

