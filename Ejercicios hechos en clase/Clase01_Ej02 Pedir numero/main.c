#include <stdio.h>
#include <stdlib.h>

int pedirSumar(void);

int main()
{
    pedirSumar();
    return 0;
}

int pedirSumar()
{
    int valorA;
    int valorB;
    int resultado;

    printf("\nIngrese un numero:");
    scanf("%d",&valorA);

    printf("\nIngrese otro numero:");
    scanf("%d",&valorB);

    resultado=valorA+valorB;

    printf("La suma es: %d",resultado);
    return 0;

}
