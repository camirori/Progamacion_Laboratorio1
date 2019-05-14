#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

#define QTY_AUTORES 3
#define QTY_LIBROS 3
#define QTY_SOCIOS 3
#define QTY_PRESTAMOS 3

int main()
{
    int opcion;
    int contadorIdAutores=0;
    int contadorIdLibros=0;
    int contadorIdSocios=0;
    int contadorIdPrestamos=0;

    Autores arrayAutores[QTY_AUTORES];
    Libros arrayLibros[QTY_LIBROS];
    Socios arraySocios[QTY_SOCIOS];
    Prestamos arrayPrestamos[QTY_PRESTAMOS];

    Autores_inicializar(arrayAutores,QTY_AUTORES);
    Libros_inicializar(arrayLibros,QTY_LIBROS);
    Socios_inicializar(arraySocios,QTY_SOCIOS);
    Prestamos_inicializar(arrayPrestamos,QTY_PRESTAMOS);

    do
    {
        utn_getUnsignedInt("\n\n1) DATOS PREVIOS \n2) OPCIONES SOCIOS \n3) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
        case 1://Datos previos
            do
            {
                utn_getUnsignedInt("\n\n1) Alta autor\n2) Modificar autor\n3) Baja autor\n4) Listar autores\n5) Alta libro\n6) Modificar libro\n7) Baja libro\n8) Listar libros\n6) Salir\n",                   //cambiar
                              "\nError",1,sizeof(int),1,11,1,&opcion);
                switch(opcion)
                {
                    case 1: //Alta
                        Autores_alta(arrayAutores,QTY_AUTORES,&contadorIdAutores);
                        break;

                    case 2: //Modificar
                        Autores_modificar(arrayAutores,QTY_AUTORES);
                        break;

                    case 3: //Baja
                        Autores_baja(arrayAutores,QTY_AUTORES);
                        break;

                    case 4://Listar
                        Autores_ordenarPorApellido(arrayAutores,QTY_AUTORES);
                        Autores_listar(arrayAutores,QTY_AUTORES);
                        break;

                    case 5: //Alta
                        Libros_alta(arrayLibros,QTY_LIBROS,&contadorIdLibros,arrayAutores,QTY_AUTORES);
                        break;

                    case 6: //Modificar
                        Libros_modificar(arrayLibros,QTY_LIBROS,arrayAutores,QTY_AUTORES);
                        break;

                    case 7: //Baja
                        Libros_baja(arrayLibros,QTY_LIBROS);
                        break;

                    case 8://Listar
                        Libros_ordenarPorTitulo(arrayLibros,QTY_LIBROS);
                        Libros_listar(arrayLibros,QTY_LIBROS);
                        break;

                    case 9://Salir
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }
            while(opcion!=9);
            break;

        case 2://Socios
            do
            {
                utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar socios \n5) Listar libros \n6) Listar autores \n7) Registar prestamo \n8) Salir\n",
                              "\nError",1,sizeof(int),1,11,1,&opcion);
                switch(opcion)
                {
                    case 1: //Alta
                        Socios_alta(arraySocios,QTY_SOCIOS,&contadorIdSocios);                   //cambiar
                        break;

                    case 2: //Modificar
                        Socios_modificar(arraySocios,QTY_SOCIOS);                   //cambiar
                        break;

                    case 3: //Baja
                        Socios_baja(arraySocios,QTY_SOCIOS);                   //cambiar
                        break;

                    case 4://Listar socios
                        Socios_ordenarPorString(arraySocios,QTY_SOCIOS);                   //cambiar
                        Socios_listar(arraySocios,QTY_SOCIOS);                   //cambiar
                        break;

                    case 5://Listar libros
                        Libros_ordenarPorTitulo(arrayLibros,QTY_LIBROS);
                        Libros_listar(arrayLibros,QTY_LIBROS);
                        break;

                    case 6://Listar Autores
                        Autores_ordenarPorApellido(arrayAutores,QTY_AUTORES);
                        Autores_listar(arrayAutores,QTY_AUTORES);
                        break;

                    case 7://Alta prestamo
                        Prestamos_alta(arrayPrestamos,QTY_PRESTAMOS,&contadorIdPrestamos);
                        break;

                    case 8://Salir
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }
            while(opcion!=8);
            break;

        case 3://Salir
            break;
        default:
            printf("\nOpcion no valida");
        }
    }
    while(opcion!=3);

    return 0;
}


/*
Entidades:
Autores:
 Código de Autor (autoincremental)
 Apellido (máximo 31 caracteres) Validar
 Nombre (máximo 31 caracteres) Validar

Libros:
 Código de Libro (autoincremental)
 Título (máximo 51 caracteres) Validar
 Código de Autor ( debe existir ) Validar

Socios:
 Código de Socio (autoincremental)
 Apellido (máximo 31 caracteres) Validar
 Nombre (máximo 31 caracteres) Validar
 Sexo ( F | M ) Validar
 Teléfono (máximo 16 caracteres) Validar
 eMail (máximo 31 caracteres) Validar
 Fecha de asociado Validar día, mes y año

Préstamos:
 Codigo de Préstamo (autoincremental)
 Codigo de Libro (debe existir) Validar
 Codigo de Socio (debe existir) Validar
 Fecha de Préstamo ( Validar día, mes y año )

*/


//Crear una opcion en alta para que valide que el dato en comun con otra entidad ya exista
//El isEmpty deberia cambiar luego de que se hayan ingresado todos los datos correctamente      Listo en entidad, falta en este proyecto
//cuando se da de baja un autor hay que dar de baja los libros con ese codigo?
