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

int Prestamos_inicializar(Prestamos array[], int size);
int Prestamos_buscarEmpty(Prestamos array[], int size, int* posicion);
int Prestamos_buscarID(Prestamos array[], int size, int valosBuscado, int* posicion);
int Prestamos_alta(Prestamos array[], int size, int* contadorID);

#endif // PRESTAMOS_H_INCLUDED


/*
Préstamos:
 Codigo de Préstamo (autoincremental)
 Codigo de Libro (debe existir) Validar
 Codigo de Socio (debe existir) Validar
 Fecha de Préstamo ( Validar día, mes y año )
*/
