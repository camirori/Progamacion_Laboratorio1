#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#include "empleado.h"

#define QTY_EMPLEADOS 3




int main()
{
    int id=0;
    int opcion;

    Empleado arrayEmpleados[QTY_EMPLEADOS];

    empleado_inicializarArrayInt(arrayEmpleados,QTY_EMPLEADOS);


    do
    {
        utn_getNumero("\n\n1) Alta \n2) Baja \n3) Ordenar \n4) Listar \n5)Salir\n","\nError",1,2,1,5,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                id++;
                empleado_alta(arrayEmpleados,QTY_EMPLEADOS,id);
                break;

            case 2: //Baja
                empleado_baja(arrayEmpleados,QTY_EMPLEADOS);
                break;

            case 3: //Ordenar
                empleado_ordenarporNombre(arrayEmpleados,QTY_EMPLEADOS);
                break;


            /*

            case 4:
                array_listarArrayString(arrayNombres,QTY_EMPLEADOS);

                break;*/

            case 5:
                break;
        }
    }
    while(opcion!=5);
    return 0;
}
