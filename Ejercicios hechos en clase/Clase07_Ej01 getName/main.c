#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char nombre[50]= "test";

    if(getName("\nNombre: ","\nError",1,5,2,nombre)==0)
    {
        printf("\nOK: %s",nombre);
    }
    else
    {
        printf("\nError: %s",nombre);
    }

    return 0;
}
