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
