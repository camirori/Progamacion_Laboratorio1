#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje, int *valorIngresado)
{
    printf("%s",mensaje);
    scanf("%d",valorIngresado);
    return 0;
}

int calculoOperaciones(int operandoA, int operandoB, int *suma, int *resta, int *division, int *multiplicacion,int *factorialA,int *factorialB)
{
    *suma=operandoA+operandoB;
    *resta=operandoA-operandoB;
    *division=operandoA/operandoB;
    *multiplicacion=operandoA*operandoB;
    *factorialA=1;
    *factorialB=1;
    int i;
    int j;

    for(i=1; i<=operandoA; i++)
    {
        *factorialA*=i;
    }
    for(j=1; j<=operandoB; j++)
    {
        *factorialB*=j;
    }

    return 0;
}

int mostrarResultados(int operandoA, int operandoB, int suma, int resta, int division, int multiplicacion,int factorialA,int factorialB)
{
    printf("\nEl resultado de %d+%d es: %d",operandoA,operandoB,suma);
    printf("\nEl resultado de %d-%d es: %d",operandoA,operandoB,resta);
    if(operandoB==0)
    {
        printf("No es posible dividir por cero");
    }
    else
    {
        printf("\nEl resultado de %d/%d es: %d",operandoA,operandoB,division);
    }
    printf("\nEl resultado de %d*%d es: %d",operandoA,operandoB,multiplicacion);
    printf("\nEl factorial de %d es: %d y El factorial de %d es: %d\n",operandoA,factorialA,operandoB,factorialB);

    return 0;
}
