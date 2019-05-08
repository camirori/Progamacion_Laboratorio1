#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

#define TEXT_SIZE 31

typedef struct
{
    int idUnico;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];

}Autores;

int Autores_inicializar(Autores array[], int size);
int Autores_buscarEmpty(Autores array[], int size, int* posicion);
int Autores_buscarID(Autores array[], int size, int valosBuscado, int* posicion);
int Autores_alta(Autores array[], int size, int* contadorID);
int Autores_baja(Autores array[], int sizeArray);
int Autores_modificar(Autores array[], int sizeArray);
int Autores_ordenarPorApellido(Autores array[],int size);
int Autores_listar(Autores array[], int size);



#endif // AUTORES_H_INCLUDED
