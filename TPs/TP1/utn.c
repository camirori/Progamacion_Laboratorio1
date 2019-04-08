#include <stdio.h>
#include <stdlib.h>

/**
*\brief Solicita el ingreso de un entero
*\param mensaje Mensaje a imprimir
*\param valorIngresado Puntero al entero ingresado por el usuario
*\return 0 sin errores, -1 parámetros inválidos
*/
int getInt(char *mensaje, int *valorIngresado)
{
    int retorno=-1;
    if(mensaje!=NULL && valorIngresado!=NULL)
    {
        printf("%s",mensaje);
        scanf("%d",valorIngresado);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Realiza las operaciones de suma, resta, division, multiplicación y factorial de dos enteros
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\param suma Puntero
*\param resta Puntero
*\param division Puntero
*\param multiplicacion Puntero
*\param factorialA Puntero
*\param factorialB Puntero
*\return 0 sin errores, -1 parámetros inválidos
*/
int calculoOperaciones(int operandoA, int operandoB, int *suma, int *resta, int *division, int *multiplicacion,int *factorialA,int *factorialB)
{
    int retorno=-1;
    if(suma!=NULL && resta!=NULL && division!=NULL && multiplicacion!=NULL && factorialA!=NULL && factorialB!=NULL)
    {
        *suma=operandoA+operandoB;
        *resta=operandoA-operandoB;
        if(operandoB!=0)
        {
            *division=operandoA/operandoB;
        }
        *multiplicacion=operandoA*operandoB;
        *factorialA=1;
        *factorialB=1;
        int i;
        int j;
        if(operandoA>=0)
        {
            for(i=1; i<=operandoA; i++)
            {
                *factorialA*=i;
            }
        }
        if(operandoB>=0)
        {
            for(j=1; j<=operandoB; j++)
            {
                *factorialB*=j;
            }
        }
        retorno=0;
    }

    return retorno;
}

/**
*\brief Imprime el resultado de las operaciones de suma, resta, division, multiplicación y factorial de dos enteros
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\param suma Resultado de la suma de operandoA y operandoB
*\param resta Resultado de la resta de operandoA y operandoB
*\param division Resultado de la division de operandoA y operandoB
*\param multiplicacion Resultado de la multiplicacion de operandoA y operandoB
*\param factorialA Resultado del factorial del operandoA
*\param factorialB Resultado del factorial del operandoB
*\return 0 sin errores
*/
int mostrarResultados(int operandoA, int operandoB, int suma, int resta, int division, int multiplicacion,int factorialA,int factorialB)
{
    printf("\nEl resultado de %d+%d es: %d",operandoA,operandoB,suma);
    printf("\nEl resultado de %d-%d es: %d",operandoA,operandoB,resta);
    if(operandoB==0)
    {
        printf("\nNo es posible dividir por cero");
    }
    else
    {
        printf("\nEl resultado de %d/%d es: %d",operandoA,operandoB,division);
    }

    printf("\nEl resultado de %d*%d es: %d",operandoA,operandoB,multiplicacion);

    if(operandoA<0)
    {
        printf("\nNo es posible calcular el factorial de %d ya que es un numero negativo",operandoA);
    }
    else
    {
        printf("\nEl factorial de %d es: %d",operandoA,factorialA);
    }

    if(operandoB<0)
    {
        printf("\nNo es posible calcular el factorial de %d ya que es un numero negativo",operandoB);
    }
    else
    {
        printf("\nEl factorial de %d es: %d\n",operandoB,factorialB);
    }

    return 0;
}
