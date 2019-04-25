#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#include "empleado.h"

#define QTY_EMPLEADOS 3

int main()
{
    int contadorId=0;
    int opcion;

    Empleado arrayEmpleados[QTY_EMPLEADOS];

    empleado_inicializarArrayInt(arrayEmpleados,QTY_EMPLEADOS);


    do
    {
        utn_getNumero("\n\n1) Alta \n2) Baja \n3) Ordenar \n4) Listar \n5)Salir\n","\nError",1,2,1,5,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                empleado_alta(arrayEmpleados,QTY_EMPLEADOS,&contadorId);
                break;

            case 2: //Baja
                empleado_baja(arrayEmpleados,QTY_EMPLEADOS);
                break;

            case 3: //Ordenar
                empleado_ordenarporNombre(arrayEmpleados,QTY_EMPLEADOS);
                break;

            case 4:
                empleado_listar(arrayEmpleados,QTY_EMPLEADOS);
                break;

            case 5:
                break;
        }
    }
    while(opcion!=5);
    return 0;
}

/*
 problemas:
 El ID empieza en 2 en lugar de 1
 Cuando se ingresan más elementos que el tamaño se reemplazan los anteriores, de abajo para arriba, en algun momento se cambia isEmpty?
 */

