#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employee.h"


#define QTY_EMPLOYEES 3 //cambiar a 1000

int main()
{
    int opcion;
    int contadorId=0;
    int flag=0;

    Employee arrayEmployee[QTY_EMPLOYEES];
    Employee_Inicializar(arrayEmployee,QTY_EMPLOYEES);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar empleados \n5)  \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                Employee_alta(arrayEmployee,QTY_EMPLOYEES,&contadorId);
                flag=1;
                break;

            case 2: //Modificar
                if(flag==0)
                {
                    printf("\nNo se han ingresado empleados aun");
                }
                else
                    Employee_modificar(arrayEmployee,QTY_EMPLOYEES);
                break;

            case 3: //Baja
                if(flag==0)
                {
                    printf("\nNo se han ingresado empleados aun");
                }
                else
                    Employee_baja(arrayEmployee,QTY_EMPLOYEES);
                break;

            case 4://Ordenar y Listar
                if(flag==0)
                {
                    printf("\nNo se han ingresado empleados aun");
                }
                else
                {
                    Employee_ordenar(arrayEmployee,QTY_EMPLOYEES);
                    Employee_listar(arrayEmployee,QTY_EMPLOYEES);
                }
                break;

            case 5://Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
