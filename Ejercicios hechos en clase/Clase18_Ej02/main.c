#include <stdio.h>
#include <stdlib.h>

#define SIZE_STR 10

int main()
{
    Empleado *pEmpleado[10];  //array punteros a empleado

    int index=0;

    char bufferId[SIZE_STR];
    char bufferNombre[SIZE_STR];
    char bufferApellido[SIZE_STR];
    char bufferEstado[SIZE_STR];

    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
            //empleado_newEmpleado que guarda los datos en un nuevo empleado y devuelve un puntero
            printf("\n%s",bufferApellido);
        }
        fclose(pFile);
        fclose(pFileBkp);
    }

    return 0;
}
