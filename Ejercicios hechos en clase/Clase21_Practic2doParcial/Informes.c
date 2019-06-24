#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ControllerCliente.h"
#include "ControllerVenta.h"
#include "utn.h"
#include "Venta.h"
#include "Cliente.h"


/*
7. Informar​ ​ventas:​​ ​Se​ ​imprimirá​ ​por​ ​pantalla​ ​las​ ​ventas​ ​realizadas.
8. Informar ventas por producto​. Se pedirá que se ingrese el códigodeunproducto y se​ ​imprimirá​ ​por​ ​pantalla​ ​las​ ​ventas​ ​realizadas​ ​de​ ​dicho​ ​producto.
9. Generar informe de ventas: ​Se generará un archivo "informe.txt" con el mismo formato​ ​que​ ​el​ ​punto​ ​7.
10.Informar cantidad de ventas por cliente: Listará por pantalla a los clientes indicando la cantidad de compras que tienen asociadas cada uno y el monto total de dichas​ ​compras
*/

//7
/** \brief Listar Venta
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int informes_ListVenta(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int j;
    int bufferIDVenta;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;
    int bufferCantidad;
    float bufferPrecio;
    float bufferMonto;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];
    int size=ll_len(pArrayList);
    Venta* pVenta;
    Cliente* pCliente;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            pVenta=ll_get(pArrayList,i);
            venta_getId(pVenta,&bufferIDVenta);
            venta_getCantidad(pVenta,&bufferCantidad);
            venta_getPrecio(pVenta,&bufferPrecio);
            venta_getIdCliente(pVenta,&bufferIdCliente);                       //cambiar
            venta_getCodProducto(pVenta,&bufferCodProducto);

            cliente_searchId(pArrayList,bufferIdCliente,&j);
            pCliente=ll_get(pArrayList,j);
            cliente_getNombre(pCliente,bufferNombre);
            cliente_getApellido(pCliente,bufferNombre);
            cliente_getDni(pCliente,bufferDni);

            bufferMonto=bufferPrecio*bufferCantidad;

            printf("\n ID Venta: %d\t Nombre: %s\t Apellido: %s\t DNI: %s\t IdCliente: %d\t CodProducto: %d\t Monto facturado: %.2f",bufferIDVenta,bufferNombre,bufferApellido,bufferDni,bufferIdCliente,bufferCodProducto,bufferMonto);                       //cambiar
        }
        retorno=0;
    }
    return retorno;
}

//8         Se imprime el listado de ventas o la cantidad de ventas?
/** \brief Listar Venta
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int informes_ListVentaPorProducto(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;
    int bufferCantidad;
    float bufferPrecio;
    int size;
    Venta* puntero;
    LinkedList* sublista=NULL;
    int criterio;
    int* pCriterio;
    pCriterio=&criterio;

    if(pArrayList!=NULL)
    {
        utn_getUnsignedInt("\nCodigo de producto: ","\nError",0,5,1,&criterio);
        sublista=ll_filter(pArrayList,venta_cmpCodProducto,pCriterio,0);
        if(sublista!=NULL)
        {
            size=ll_len(sublista);
            for(i=0;i<size;i++)
            {
                puntero=ll_get(sublista,i);
                venta_getId(puntero,&bufferID);
                venta_getCantidad(puntero,&bufferCantidad);
                venta_getPrecio(puntero,&bufferPrecio);
                venta_getIdCliente(puntero,&bufferIdCliente);                       //cambiar
                venta_getCodProducto(puntero,&bufferCodProducto);

                printf("\n ID: %d  IdCliente: %d   CodProducto: %d   Cantidad: %d   Precio: %f",bufferID,bufferIdCliente,bufferCodProducto,bufferCantidad,bufferPrecio);                       //cambiar
            }
            retorno=0;
        }
    }
    return retorno;
}

//9. Generar informe de ventas: ​Se generará un archivo "informe.txt" con el mismo formato​ ​que​ ​el​ ​punto​ ​7.

/** \brief Guarda los datos de los empleados en el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 */
int informes_saveAsText(char* path , LinkedList* pArrayList)
{
    int i;
    Venta* pVenta=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferIDVenta;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;                       //cambiar
    int bufferCantidad;
    float bufferPrecio;
    int contador=0;

    int j;
    float bufferMonto;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];
    Cliente* pCliente;

    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pVenta=ll_get(pArrayList,i);
                venta_getId(pVenta,&bufferIDVenta);
                venta_getCantidad(pVenta,&bufferCantidad);
                venta_getPrecio(pVenta,&bufferPrecio);
                venta_getIdCliente(pVenta,&bufferIdCliente);                       //cambiar
                venta_getCodProducto(pVenta,&bufferCodProducto);

                cliente_searchId(pArrayList,bufferIdCliente,&j);
                pCliente=ll_get(pArrayList,j);
                cliente_getNombre(pCliente,bufferNombre);
                cliente_getApellido(pCliente,bufferNombre);
                cliente_getDni(pCliente,bufferDni);

                bufferMonto=bufferPrecio*bufferCantidad;

                if(fprintf(pFile,"\n ID Venta: %d\t Nombre: %s\t Apellido: %s\t DNI: %s\t IdCliente: %d\t CodProducto: %d\t Monto facturado: %.2f",bufferIDVenta,bufferNombre,bufferApellido,bufferDni,bufferIdCliente,bufferCodProducto,bufferMonto)>100)                       //cambiar
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}
