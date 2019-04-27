#define SIZE_TEXTO 20

int array_inicializarArrayString(char array[][SIZE_TEXTO], int size);
int array_inicializarArrayInt(int* array, int size, int valor);
int array_buscarPrimerOcurrenciaInt (int* array, int size, int valorBuscado);
int array_buscarPrimerOcurrenciaString(char array[][SIZE_TEXTO], int size, char* valorBuscado);

int array_listarArray(int* array1, char array2[][SIZE_TEXTO], char array3[][SIZE_TEXTO], int size);  // no se puede hacer sin sizetexto?
int array_listarArrayString(char array[][SIZE_TEXTO], int size);

int array_ordenarPorSeleccion(int* array, int size);
int array_ordenarPorInsercion(int* array, int size);
int array_ordenarShell(int* array, int size);
int array_ordenarPorInsercionString(char array[][SIZE_TEXTO], int size);

