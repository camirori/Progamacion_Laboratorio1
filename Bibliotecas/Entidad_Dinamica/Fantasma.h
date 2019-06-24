#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define STR_SIZE 128

typedef struct                          //Replace Fantasma (tipo) y entidad (f)     campos: Int1 + int1 // Int2 + int2 // Nombre2 + nombre2
{
    int id;
    char nombre[STR_SIZE];
    char nombre2[STR_SIZE];
    int int1;
    int int2;
}Fantasma;

Fantasma* entidad_new();
Fantasma* entidad_newParametros(char* idStr,char* nombreStr,char* nombre2Str,char* int1Str, char* int2Str);
Fantasma* entidad_newBinario(Fantasma entidad);

void entidad_delete();

int entidad_setIdStr(Fantasma* this,char* id);
int entidad_setId(Fantasma* this,int id);
int entidad_getId(Fantasma* this,int* id);

int entidad_setNombre(Fantasma* this,char* nombre);
int entidad_getNombre(Fantasma* this,char* nombre);

int entidad_setNombre2(Fantasma* this,char* nombre2);
int entidad_getNombre2(Fantasma* this,char* nombre2);

int entidad_setInt1Str(Fantasma* this,char* int1);
int entidad_setInt1(Fantasma* this,int int1);
int entidad_getInt1(Fantasma* this,int* int1);

int entidad_setInt2Str(Fantasma* this,char* int2);
int entidad_setInt2(Fantasma* this,int int2);
int entidad_getInt2(Fantasma* this,int* int2);

int entidad_cmpId(void* punteroI, void* punteroJ);
int entidad_cmpName(void* this1, void* this2);

int entidad_searchId(LinkedList* pArrayList, int valorBuscado, int* index);
int entidad_searchMaxId(LinkedList* pArrayList, int* maxID);

#endif // FANTASMA_H_INCLUDED
