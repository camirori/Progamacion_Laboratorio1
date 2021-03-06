#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ControllerCliente.h"
#include "ControllerVenta.h"
#include "utn.h"
#include "Informes.h"

int main()
{
    int opcion;
    int ultimoIdClientes=0;
    int ultimoIdVentas=0;

    LinkedList* listaClientes= ll_newLinkedList();
    LinkedList* listaVentas= ll_newLinkedList();

    do
    {
        if(utn_getUnsignedInt("\n\n1) Alta cliente \n2) Modificacion cliente\n3) Baja cliente\n4) Listar​ ​clientes\n5) Realizar venta\n6) Anular​ ​venta\n7) Informar​ ​ventas\n8) Informar ventas por producto\n9) Generar informe de ventas\n10) Informar cantidad de ventas por cliente\n11) Salir\n",                   //cambiar
                                "\nError",1,sizeof(int),1,&opcion)!=0)
            opcion=11;   //salir
        else
        {
            switch(opcion)
            {
                case 1: //Alta cliente
                    printf("\nAlta cliente");
                    controllerCliente_addCliente(listaClientes,&ultimoIdClientes);
                    break;

                case 2: //Modificacion cliente
                    printf("\nModificacion cliente");
                    controllerCliente_editCliente(listaClientes);
                    break;

                case 3: //Baja cliente
                    printf("\nBaja cliente");
                    if(1)//if    ventas buscar ID cliente == false
                        controllerCliente_removeCliente(listaClientes);
                    else
                        printf("\nEl cliente no puede ser dado de baja ya que tiene ventas asociadas");
                    break;

                case 4: //Listar​ ​clientes + ordenar
                    printf("\nListar​ ​clientes");
                    controllerCliente_sortCliente(listaClientes);
                    controllerCliente_ListCliente(listaClientes);
                    break;

                case 5:
                    printf("\nRealizar venta");
                    controllerVenta_addVenta(listaVentas,&ultimoIdVentas);              //no se pide el precio?
                    break;

                case 6:
                    printf("\nAnular​ ​venta");
                    controllerVenta_removeVenta(listaVentas);
                    break;

                case 7:
                    printf("\nInformar​ ​ventas");
                    controllerVenta_ListVenta(listaVentas);
                    break;

                case 8:
                    printf("\nInformar ventas por producto");       //falta
                    informes_ListVentaPorProducto(listaVentas);
                    break;

                case 9:
                    printf("\nGenerar informe de ventas");          //Se generara un archivo "informe.txt" con el mismo formato​ ​que​ ​el​ ​punto​ ​7.
                    informes_saveAsText("informe.txt",listaVentas,listaClientes);
                    break;

                case 10:
                    printf("\nInformar cantidad de ventas por cliente"); //Listará por pantalla a los clientes indicando la cantidad de compras que tienen asociadas cada uno y el monto total de dichas​ ​compras.
                    Informes_listarCriterioContadorAcumulado(listaClientes,listaVentas);
                    break;

                case 11://Salir
                    break;
                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(opcion!=11);
    return 0;
}

/*
Cliente:
    Alta,modificar,baja,listar

Venta:
    Alta,Baja,listar,

Informe:
    venta por producto, guardar en archivo ventas, Informar cantidad de ventas por cliente

*/
