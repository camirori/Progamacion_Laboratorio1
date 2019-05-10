#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define TEXT_SIZE 51

typedef struct
{
    int idUnico;
    int isEmpty;

    char name[TEXT_SIZE];
    char lastName[TEXT_SIZE];
    float salary;
    int sector;
}Employee;

int Employee_inicializar(Employee array[], int size);
int Employee_buscarEmpty(Employee array[], int size, int* posicion);
int Employee_buscarID(Employee array[], int size, int valorBuscado, int* posicion);
int Employee_alta(Employee array[], int size, int* contadorID);
int Employee_baja(Employee array[], int sizeArray);
int Employee_modificar(Employee array[], int sizeArray);
int Employee_ordenar(Employee array[],int size);
int Employee_listar(Employee array[], int size);
int Employee_informarSalario(Employee array[], int size);


#endif // EMPLOYEE_H_INCLUDED
