#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#define TEXT_SIZE 51

typedef struct
{
    int idUnico;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char titulo[TEXT_SIZE];
    int idAutor;
}Libros;


int Libros_inicializar(Libros array[], int size);
int Libros_buscarEmpty(Libros array[], int size, int* posicion);
int Libros_buscarID(Libros array[], int size, int valosBuscado, int* posicion);
int Libros_alta(Libros array[], int size, int* contadorID);
int Libros_baja(Libros array[], int sizeArray);
int Libros_modificar(Libros array[], int sizeArray);
int Libros_ordenarPorTitulo(Libros array[],int size);
int Libros_listar(Libros array[], int size);


#endif // LIBROS_H_INCLUDED
