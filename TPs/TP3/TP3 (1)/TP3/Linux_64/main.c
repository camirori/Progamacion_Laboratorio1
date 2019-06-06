#include <stdio.h>
#include <stdlib.h>
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
    LinkedList* listaEmpleados = ll_newLinkedList();
    int ultimoId=1;

    do{
        utn_getUnsignedInt("\nOpcion ","\nError",1,3,1,&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 3:
                controller_addEmployee(listaEmpleados, &ultimoId);
                break;

            case 6:
                printf("Lista");
                controller_ListEmployee(listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}

/*
F() para obtener el ultimo ID
*/
