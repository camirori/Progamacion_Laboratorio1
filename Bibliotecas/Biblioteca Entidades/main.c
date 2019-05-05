#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "entidades.h"  //cambiar por nombre entidad


#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdTipo=0;                   //cambiar

    Tipo arrayTipo[QTY_TIPO];                   //cambiar
    Tipo_Inicializar(arrayTipo,QTY_TIPO);                   //cambiar

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                Tipo_alta(arrayTipo,QTY_TIPO,&contadorIdTipo);                   //cambiar
                break;

            case 2: //Modificar
                Tipo_modificar(arrayTipo,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                Tipo_baja(arrayTipo,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                Tipo_listar(arrayTipo,QTY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                Tipo_ordenarPorString(arrayTipo,QTY_TIPO);                   //cambiar
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
