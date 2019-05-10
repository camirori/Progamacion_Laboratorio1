#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employee.h"

#define QTY_EMPLOYEES 1000

int main()
{
    int opcion;
    int contadorId=0;
    int flag=0;

    Employee arrayEmployee[QTY_EMPLOYEES];
    Employee_inicializar(arrayEmployee,QTY_EMPLOYEES);

    do
    {
        if(utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar empleados \n5) Informar salario total y promedio  \n6) Salir\n","\nError",1,2,1,&opcion)!=0)
            opcion=6;
        else
            switch(opcion)
            {
                case 1: //Alta
                    if(Employee_alta(arrayEmployee,QTY_EMPLOYEES,&contadorId)==0)
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
                    if(flag==0)
                    {
                        printf("\nNo se han ingresado empleados aun");
                    }
                    else
                        Employee_informarSalario(arrayEmployee,QTY_EMPLOYEES);
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
