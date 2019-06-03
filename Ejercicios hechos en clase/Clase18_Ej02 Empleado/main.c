#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "utn.h"

int main()
{
    Empleado** lista=NULL;     //puntero al array de punteros
    int index=0;
    int sizeLista=0;
    int ultimoId;     //hay que tener registro del màx id utilizado, sea ingresado o del archivo, para saber prox id a asignar

    Emp_newArchivo(lista,&index,&ultimoId,&sizeLista);
    printf("Index %d Size lista %d Ultimo ID %d",index,sizeLista,ultimoId);
    if(lista==NULL)
        printf("NULL");
    Emp_alta(lista,&sizeLista,&ultimoId,&index);

    //las bajas pueden ser logicas (cambiar estado) o fisicas (borrar memoria)

    return 0;
}

//tengo que saber cual es la ultima posicion util del array
//hacer funcion dumpPersonas a la que le paso el array y lo escribo en el archivo, con fprintf, cada vez que hago un alta sobreescribo
