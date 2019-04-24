#include <stdio.h>
#include <stdlib.h>

struct sFecha
{
    int day;
    int month;
    int year;
}



int main()
{



    return 0;
}

//Estructura: no lo vamos a usar
/*
struct sEmpleado            //nombre de la estructura
{
    int idEmpleado;         //siempre
    int isEmpty;            //siempre

    //-----------------
    char nombre[50];
    char apellido[50];
    char dni[30];
}

struct sEmpleado auxiliarEmpleado[500];  //igual que:
struct sEmpleado *pEmpleado;

pEmpleado= &auxiliarEmpleado[114];   //cargo direccion de memoria en el puntero
pEmpleado->apellido             //para acceder a un elemento de la estructura a traves del puntero
                                    //si no se carga el subindice se entiene que es la posicion 0

struct producto
{
    int idProducto;
    int isEmpty;

    char nombre;
    char descricpion;
    //fecha > estructura
}
*/
//************************************
// Tipo de dato
typedef struct
{
    int idEmpleado;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char nombre[50];
    char apellido[50];
    char dni[30];
}Empleado;                  //Mayuscula

Empleado auxiliarEmpleado[500];
Empleado *pEmpleado;


