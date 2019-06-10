#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int ultimoId=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        if(utn_getUnsignedInt("\n\n1) Cargar desde archivo de texto \n2) Cargar desde archivo binario \n3) Alta \n4) Modificar \n5) Baja \n6) Listar\n7) Ordenar \n8) Guardar en archivo de texto\n9) Guardar en archivo binario\n10) Salir\n",
                                "\nError",1,sizeof(int),1,&option)!=0)
            option=10;   //salir
        else
        {
            switch(option)
            {
                case 1:
                    controller_loadFromText("data.csv",listaEmpleados);
                    employee_searchMaxId(listaEmpleados,&ultimoId);
                    break;

                case 2:
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    employee_searchMaxId(listaEmpleados,&ultimoId);
                    break;

                case 3:
                    printf("\nAlta");
                    controller_addEmployee(listaEmpleados,&ultimoId);
                    break;

                case 4:
                    printf("\nModificar");
                    controller_editEmployee(listaEmpleados);
                    break;

                case 5:
                    printf("\nBaja");
                    controller_removeEmployee(listaEmpleados);
                    break;

                case 6:
                    printf("\nLista");
                    controller_ListEmployee(listaEmpleados);
                    break;

                case 7:
                    printf("\nOrdenar");
                    controller_sortEmployee(listaEmpleados);
                    break;

                case 8:
                    controller_saveAsText("data.bkp",listaEmpleados);
                    break;

                case 9:
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    break;
                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(option != 10);
    return 0;
}


/*
//Puntero a funcion
int fx(int i, int(*pFuncion)(void*,void*))
{
    pFuncion(a,b);
}
*/
