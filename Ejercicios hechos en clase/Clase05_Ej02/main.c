#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS 5


int burbujeo(int *A, int limite);
int swap(int* A,int i);



int main()
{
    int A[CANTIDAD_NUMEROS]={8,4,6,1};
    int limite=CANTIDAD_NUMEROS;
    int i;

    /*
    for(i=0;i<CANTIDAD_NUMEROS;i++)
    {
        scanf("%d",A[i]);
    }*/

    burbujeo(A,limite);


    for(i=0;i<CANTIDAD_NUMEROS;i++)
    {
        printf("%d",A[i]);
    }

    return 0;
}

int burbujeo(int *A, int limite)
{
    int flagSwap;
    int i;

    do
    {
        for(i=0;i<limite-1;i++)
        {
            flagSwap=0;
            if(A[i]>A[i+1])
            {
                swap(A,i);

                flagSwap=1;
            }
        }
    }
    while(flagSwap); // si hubo algun swap se da una vuelta mas

    return 0;
}

int swap(int* A,int i)
{
    int buffer=*(A+i);
    *(A+i)=*(A+i+1);
    *(A+i+1)=buffer;

    return 0;
}

