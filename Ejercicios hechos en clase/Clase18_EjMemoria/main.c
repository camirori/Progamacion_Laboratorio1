#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int* pInt;
    int* auxPuntero;
    int index=0;


    auxPuntero=(int*)malloc(sizeof(int));       //creo un int en forma dinamica
    printf("\nOk1");
    if(auxPuntero!=NULL)
    {
        pInt=auxPuntero;
        printf("\nOk2");

        *(pInt+index)=1;

        index++;
        auxPuntero=(int*)realloc(pInt,sizeof(int)*(index+1));   //lo convierto en un array de int
        printf("\nOk3");
        if(auxPuntero!=NULL)
        {
            pInt=auxPuntero;
            printf("\nOk4");
            *(pInt+index)=2;
        }
        printf("%d %d",*pInt,*(pInt+1));
    }

    int** pPuntero;
    int** ppAux;



    return 0;
}


