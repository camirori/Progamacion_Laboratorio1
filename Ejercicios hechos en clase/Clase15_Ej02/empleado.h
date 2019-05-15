#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED



typedef struct
{
    int id;
    int estado;         //ya no se usa isEmpty
    char nombre[50];
    float peso;
}Empleado;

#endif // EMPLEADO_H_INCLUDED

Empleado* Emp_new(void);            //constructor
int Emp_delete(Empleado* this);       //destructor

int Emp_setId(Empleado* this, int id);          //this > contexto
int Emp_getId(Empleado* this, int* resultado);          //para cada campo hacer un set y get
int Emp_setPeso(Empleado* this, float peso);
int Emp_getPeso(Empleado* this, float* resultado);
int Emp_setNombre(Empleado* this, char* nombre);
int Emp_getNombre(Empleado* this, char* resultado);
int Emp_setEstado(Empleado* this, int estado);
int Emp_getEstado(Empleado* this, int* resultado);

int Emp_nuevoEmpleado(Empleado* pEmpleado[], int* indice);

//se puede crear una funcion que cree estas funciones
