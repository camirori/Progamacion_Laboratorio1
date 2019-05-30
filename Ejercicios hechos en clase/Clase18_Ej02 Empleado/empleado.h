#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define SIZE_STR 10

typedef struct
{
    int id;
    int estado;         //ya no se usa isEmpty
    char nombre[SIZE_STR];
    char apellido[SIZE_STR];
}Empleado;

#endif // EMPLEADO_H_INCLUDED


Empleado* Emp_new(void);
Empleado* Emp_newStr(char *id, char *nombre, char *apellido, char *estado);
Empleado** Emp_newPointer(Empleado* arrayPunteros[], int i);
int Emp_newArchivo(Empleado** pPuntero, int* index);


int Emp_delete(Empleado* this);
int Emp_deleteP(Empleado** this);

int Emp_setId(Empleado* this, int id);
int Emp_setIdStr(Empleado* this, char *id);
int Emp_getId(Empleado* this, int* resultado);
int Emp_getIdStr(Empleado* this, char* resultado);

int Emp_setPeso(Empleado* this, float peso);
int Emp_getPeso(Empleado* this, float* resultado);

int Emp_setNombre(Empleado* this, char* nombre);
int Emp_getNombre(Empleado* this, char* resultado);

int Emp_setApellido(Empleado* this, char* apellido);
int Emp_getApellido(Empleado* this, char* resultado);

int Emp_setEstado(Empleado* this, int estado);
int Emp_setEstadoStr(Empleado* this, char* estado);
int Emp_getEstado(Empleado* this, int* resultado);


int Empleado_buscarID(Empleado** this, int size, int valorBuscado, int* posicion);
