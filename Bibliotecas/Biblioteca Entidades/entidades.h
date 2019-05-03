#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idEntidad;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    float varFloat;
    char varChar;
    char varLongString[TEXT_SIZE];

}Tipo;

/*
Init
BuscarEmpty
buscarID
buscarString
Alta
Baja
Modificar
Ordenar
Listar
*/

int Tipo_Inicializar(Tipo array[], int size);                                    //cambiar Tipo
int Tipo_buscarEmpty(Tipo array[], int size, int* posicion);                    //cambiar Tipo
int Tipo_buscarInt(Tipo array[], int size, int valosBuscado, int* posicion);                    //cambiar Tipo
int Tipo_buscarString(Tipo array[], int size, char* valorBuscado, int* indice);                    //cambiar Tipo
int Tipo_alta(Tipo array[], int size, int* contadorID);                          //cambiar Tipo
int Tipo_baja(Tipo array[], int sizeArray);                                      //cambiar Tipo
int Tipo_bajaValorRepetidoInt(Tipo array[], int sizeArray, int valorBuscado);
int Tipo_modificar(Tipo array[], int sizeArray);                                //cambiar Tipo
int Tipo_ordenarPorString(Tipo array[],int size);                              //cambiar Tipo
int Tipo_listar(Tipo array[], int size);                      //cambiar Tipo



#endif // TIPO_H_INCLUDED
