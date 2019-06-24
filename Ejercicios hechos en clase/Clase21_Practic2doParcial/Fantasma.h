#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define STR_SIZE 128

typedef struct
{
    int id;
    char nombre[STR_SIZE];
    int horasTrabajadas;
    int sueldo;
}Fantasma;

Fantasma* entidad_new();
Fantasma* entidad_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Fantasma* entidad_newBinario(Fantasma empleado);

void entidad_delete();

int entidad_setIdStr(Fantasma* this,char* id);
int entidad_setId(Fantasma* this,int id);
int entidad_getId(Fantasma* this,int* id);

int entidad_setNombre(Fantasma* this,char* nombre);
int entidad_getNombre(Fantasma* this,char* nombre);

int entidad_setHorasTrabajadasStr(Fantasma* this,char* horasTrabajadas);
int entidad_setHorasTrabajadas(Fantasma* this,int horasTrabajadas);
int entidad_getHorasTrabajadas(Fantasma* this,int* horasTrabajadas);

int entidad_setSueldoStr(Fantasma* this,char* sueldo);
int entidad_setSueldo(Fantasma* this,int sueldo);
int entidad_getSueldo(Fantasma* this,int* sueldo);

int entidad_cmpId(void* punteroI, void* punteroJ);
int entidad_cmpName(void* this1, void* this2);

int entidad_searchId(LinkedList* pArrayList, int valorBuscado, int* index);
int entidad_searchMaxId(LinkedList* pArrayList, int* maxID);

#endif // FANTASMA_H_INCLUDED
