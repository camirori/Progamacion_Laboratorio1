#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int i;  // està en el stack de main, existe mientras exista main
    int* pEntero;

    pEntero=&i;

    *pEntero=14;
    */


    //para crearlo de manera dinamica:

    int* pEntero;
    int* pEnteroAux;

    pEntero=(int*)malloc(sizeof(int));    //guardo en pEntero la direcciòn de memoria con espacio para almacenar un int
                                        //malloc utiliza un espacio para hacerse una anotacion y reserva los siguientes
                                        //(int*) para que deje de ser un puntero a void y pasa a ser un puntero a int

    pEntero=(int*)malloc(sizeof(int)*100);     //guardo memoria para un array de 100 enteros
    if(pEntero!=NULL)
    {
        *(pEntero+2)=14;                        //se desplaza 16 lugares, apuntando al segundo elemento del array
    }

    pEnteroAux=(int*)realloc(pEntero,sizeof(int)*1000);         //cambio el tamaño de memoria reservada, puede que cambie la direccion de memoria
                                                    //return puntero a la nueva posicion
    if(pEnteroAux!=NULL)
    {
        pEntero=pEnteroAux;
    }

    free(pEntero);                         //libera la memoria reservada

    //se puede usar tmb con un tipo de dato estructura, en lugar de int

    Empleado* pArrayEmpleados;
    Empleado* pArrayEmpleadosAux;
    pArrayEmpleados=(Empleado*)malloc(sizeof(Empleado)*100);
    Empleado auxE;
    Empleado* pEmp;

    auxE.legajo;
    pEmp=&auxE.legajo;
    pEmp->legajo=111;

    if(pArrayEmpleados!=NULL)
    {
        *(pArrayEmpleados+2).legajo=222;    //uno u otro, ser constante
        (pArrayEmpleados+2)->legajo=222;
    }


    return 0;
}
/*

malloc() > reserva espacio de memoria, no la libera hasta que no se le indique
realloc()
            > ambos devuelven un puntero a la posicion de memoria

cuando la ram no tiene mas espacio se empieza a hacer swap a disco
segmentation fault > no encuentra memoria y devuelve null


//realloc no se va  ausar porque se va a ir almacenando lugar para cada empleado por separado. Se va a crear o destruir
//cuando tenga que ordenar, el swap va a ser solo de punteros en lugar de cada campo
ya no se va a crear un arrayEmpleados en el main sino un array de punteros

getEdad > devuelve edad
setEdad > se tiene la fecha de nacimiento y calcula la edad
