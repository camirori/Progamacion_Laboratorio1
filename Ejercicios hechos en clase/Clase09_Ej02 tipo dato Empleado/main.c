#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#include "empleado.h"

#define QTY_EMPLEADOS 3

int main()
{

    int opcion;
    int contadorId=0;   //si lo declaro antes de opcion se cambia a 1 despues de inicializar arrayInt, por que????????

    Empleado arrayEmpleados[QTY_EMPLEADOS];
    empleado_inicializarArrayInt(arrayEmpleados,QTY_EMPLEADOS);

    do
    {
        utn_getNumero("\n\n1) Alta \n2) Baja \n3) Ordenar \n4) Listar \n5) Modificar \n6) Salir\n","\nError",1,2,1,6,1,&opcion);
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

            case 4: //Listar
                empleado_listar(arrayEmpleados,QTY_EMPLEADOS);
                break;

            case 5://Modificar

                break;

            case 6://Salir
                break;
        }
    }
    while(opcion!=6);
    return 0;
}

/*
 problemas:
 El ID empieza en 2 en lugar de 1
 Cuando se ingresan más elementos que el tamaño se reemplazan los anteriores, de abajo para arriba, en algun momento se cambia isEmpty?
 */

