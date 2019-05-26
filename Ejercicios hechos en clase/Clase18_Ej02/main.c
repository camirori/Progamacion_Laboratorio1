#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "utn.h"

int main()
{
    FILE *pFile=NULL;
    FILE *pFileBkp=NULL;
    pFile=fopen("data.csv","r");    //direccìon archivo, modo de arpetura
    pFileBkp=fopen("data_bkp.csv","w");

    Empleado** pPuntero;     //puntero al array de punteros
    Empleado** auxPuntero;

    int index=0;

    char bufferId[SIZE_STR];
    char bufferNombre[SIZE_STR];
    char bufferApellido[SIZE_STR];
    char bufferEstado[SIZE_STR];


    if(pFile!=NULL && pFileBkp!=NULL)
    {
        printf("\nOk1");
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
            //printf("\nId: %s    Nombre: %s  Apellido: %s  Estado: %s",bufferId,bufferNombre,bufferApellido,bufferEstado);

            if(strcmp(bufferNombre,"first_name")==0)
                continue;

            printf("\nOk2");
            auxPuntero=Emp_newPointer(pPuntero,index+1);

            if(auxPuntero!=NULL)
            {
                pPuntero=auxPuntero;

                printf("\nOk3");

                *(pPuntero+index)=Emp_newStr(bufferId,bufferNombre,bufferApellido,bufferEstado);
                if((pPuntero+index)!=NULL)
                {
                    printf("\nOk9");

                    printf("\nId: %d    Nombre: %s  Apellido: %s  Estado: %s",(*(pPuntero+index))->id,(*(pPuntero+index))->nombre,(*(pPuntero+index))->apellido,(*(pPuntero+index))->estado);

                }
                index++;

                if(index==10)
                    break;
            }
        }
        fclose(pFile);
        fclose(pFileBkp);
    }

    return 0;
}
