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
*\brief Calcula la suma de dos enteros e imprime el resultado
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\return 0 sin errores
*/
int sumo(int operandoA, int operandoB)
{
    int suma=operandoA+operandoB;
    printf("\nEl resultado de %d+%d es: %d",operandoA,operandoB,suma);
    return 0;
}

/**
*\brief Calcula la resta de dos enteros e imprime el resultado
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\return 0 sin errores
*/
int resto(int operandoA, int operandoB)
{
    int resta=operandoA-operandoB;
    printf("\nEl resultado de %d-%d es: %d",operandoA,operandoB,resta);
    return 0;
}

/**
*\brief Calcula la multiplicación de dos enteros e imprime el resultado
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\return 0 sin errores
*/
int multiplico(int operandoA, int operandoB)
{
    int multiplicacion=operandoA*operandoB;
    printf("\nEl resultado de %d*%d es: %d",operandoA,operandoB,multiplicacion);
    return 0;
}

/**
*\brief Calcula la división de dos enteros e imprime el resultado
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\return 0 sin errores
*/
int divido(int operandoA, int operandoB)
{
    int division;
    if(operandoB==0)
    {
        printf("\nNo es posible dividir por cero");
    }
    else
    {
        division=operandoA/operandoB;
        printf("\nEl resultado de %d/%d es: %d",operandoA,operandoB,division);
    }
    return 0;
}

/**
*\brief Calcula el factorial de un entero e imprime el resultado
*\param operandoA Entero ingresado por el usuario
*\return 0 sin errores
*/
int factorial(int operandoA)
{
    int factorialA;
    if(operandoA<0)
    {
        printf("\nNo es posible calcular el factorial de %d ya que es un numero negativo",operandoA);
    }
    else
    {
        factorialA=1;
        int i;
        for(i=2; i<=operandoA; i++)
        {
            factorialA*=i;
        }
        printf("\nEl factorial de %d es: %d",operandoA,factorialA);
    }
    return 0;
}

/**
*\brief Realiza las operaciones de suma, resta, division, multiplicación y factorial de dos enteros
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\return 0 sin errores
*/
int calculoOperaciones(int operandoA, int operandoB)
{
    sumo(operandoA,operandoB);
    resto(operandoA,operandoB);
    multiplico(operandoA,operandoB);
    divido(operandoA,operandoB);
    factorial(operandoA);

    return 0;
}

/**
*\brief Verifica que los operadores A y B se hayan inicializado
*\param verificadorA Indica si el operador A se ha inicializado
*\param verificadorB Indica si el operador B se ha inicializado
*\return 0 sin errores
*/
int verificador(int verificadorA,int verificadorB)
{
    int retorno=0;
    if(verificadorA==0)
    {
        printf("\nAun no ha ingresado el primer operando. Elija la opcion 1 para hacerlo.");
        retorno=-1;
    }
    else if(verificadorB==0)
    {
        printf("\nAun no ha ingresado el segundo operando. Elija la opcion 2 para hacerlo.");
        retorno=-1;
    }
    return retorno;
}

