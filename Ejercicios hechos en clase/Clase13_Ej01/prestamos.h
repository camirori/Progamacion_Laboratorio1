#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;         //siempre
    int isEmpty;            //siempre
    //-----------------
    int idLibro;
    int idSocio;
    char fechaPrestamo[TEXT_SIZE];

}Prestamos;

#endif // PRESTAMOS_H_INCLUDED


/*
Préstamos:
 Codigo de Préstamo (autoincremental)
 Codigo de Libro (debe existir) Validar
 Codigo de Socio (debe existir) Validar
 Fecha de Préstamo ( Validar día, mes y año )
*/
