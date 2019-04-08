/******************************************
* Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*   1. Ingresar 1er operando (A=x)
*   2. Ingresar 2do operando (B=y)
*   3. Calcular todas las operaciones
*       a) Calcular la suma (A+B)
*       b) Calcular la resta (A-B)
*       c) Calcular la division (A/B)
*       d) Calcular la multiplicacion (A*B)
*       e) Calcular el factorial (A!)
*   4. Informar resultados
*       a) “El resultado de A+B es: r”
*       b) “El resultado de A-B es: r”
*       c) “El resultado de A/B es: r” o “No es posible dividir por cero”
*       d) “El resultado de A*B es: r”
*       e) “El factorial de A es: r1 y El factorial de B es: r2”
*   5. Salir
* • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte, que contenga las funciones para realizar las cinco operaciones.
* • En el menú deberán aparecer los valores actuales cargados en los operandos A y B (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
* • Deberán contemplarse los casos de error (división por cero, etc)
* • Documentar todas las funciones
*
*
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int mensajeMenu(int verificadorA, int verificadorB, int operandoA, int operandoB);

int main()
{
    int opcion;
    int operandoA;
    int operandoB;
    int suma;
    int resta;
    int division;
    int multiplicacion;
    int factorialA;
    int factorialB;
    int verificadorA=0;
    int verificadorB=0;
    int verificadorCalculo=0;

    while(opcion!=5)
    {
        mensajeMenu(verificadorA,verificadorB,operandoA,operandoB);
        getInt("",&opcion);

        switch(opcion)
        {
            case 1:
                getInt("\nIngrese primer operando ",&operandoA);
                verificadorA=1;
                break;
            case 2:
                getInt("\nIngrese segundo operando ",&operandoB);
                verificadorB=1;
                break;
            case 3:
                if(verificadorA==0)
                {
                    printf("\nAun no ha ingresado el primer operando. Elija la opcion 1 para hacerlo.");
                }
                else if(verificadorB==0)
                {
                    printf("\nAun no ha ingresado el segundo operando. Elija la opcion 2 para hacerlo.");
                }
                else
                {
                    calculoOperaciones(operandoA,operandoB,&suma,&resta,&division,&multiplicacion,&factorialA,&factorialB);
                    verificadorCalculo=1;
                }
                break;
            case 4:
                if(verificadorCalculo==0)
                {
                    printf("\nAun no ha realizado el calculo de las operaciones. Elija la opcion 3 para hacerlo.");
                }
                else
                {
                    mostrarResultados(operandoA,operandoB,suma,resta,division,multiplicacion,factorialA,factorialB);
                }
                break;
            case 5:
                break;
        }
    }

    return 0;
}

/**
*\brief Imprime el menu de opciones
*\param verificadorA Verifica que A se haya inicializado
*\param verificadorB Verifica que B se haya inicializado
*\param operandoA Entero ingresado por el usuario
*\param operandoB Entero ingresado por el usuario
*\return 0 sin errores
*/
int mensajeMenu(int verificadorA, int verificadorB, int operandoA, int operandoB)
{
    if(verificadorA==0 && verificadorB==0)
    {
        printf("\n1 Ingresar 1er operando (A=x)\n2 Ingresar 2do operando (B=y)\n3 Calcular todas las operaciones \n4 Informar resultados \n5 Salir\n");
    }
    else if(verificadorA!=0 && verificadorB==0)
    {
        printf("\n1 Ingresar 1er operando (A=%d)\n2 Ingresar 2do operando (B=y)\n3 Calcular todas las operaciones \n4 Informar resultados \n5 Salir\n",operandoA);
    }
    else if(verificadorA==0 && verificadorB!=0)
    {
        printf("\n1 Ingresar 1er operando (A=x)\n2 Ingresar 2do operando (B=%d)\n3 Calcular todas las operaciones \n4 Informar resultados \n5 Salir\n",operandoB);
    }
    else
    {
        printf("\n1 Ingresar 1er operando (A=%d)\n2 Ingresar 2do operando (B=%d)\n3 Calcular todas las operaciones \n4 Informar resultados \n5 Salir\n",operandoA,operandoB);
    }
    return 0;
}



