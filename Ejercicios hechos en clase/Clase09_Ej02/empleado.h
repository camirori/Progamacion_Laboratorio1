#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct empleados
{
    int idEmpleado;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char nombre[50];

}Empleado;

int empleado_inicializarArrayInt(Empleado array[], int size);
int empleado_buscarPrimerOcurrenciaInt (Empleado array[], int size, int valorBuscado, int* indice);
int empleado_buscarNombre(Empleado array[], int size, char* valorBuscado, int* indice);
int empleado_alta(Empleado array[], int size, int id);
int empleado_baja(Empleado array[], int size);
int empleado_ordenarporNombre(Empleado array[],int size);




#endif // EMPLEADO_H_INCLUDED
