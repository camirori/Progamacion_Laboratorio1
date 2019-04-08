/******************************************
* Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*   1. Ingresar 1er operando (A=x)
*   2. Ingresar 2do operando (B=y)
*   3. Calcular la suma (A+B)
*   4. Calcular la resta (A-B)
*   5. Calcular la division (A/B)
*   6. Calcular la multiplicacion (A*B)
*   7. Calcular el factorial (A!)
*   8. Calcular todas las operaciones
*   9. Salir
* • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte, que contenga las funciones para realizar las cinco operaciones.
* • En el menú deberán aparecer los valores actuales cargados en los operandos A y B (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
* • Deberán contemplarse los casos de error (división por cero, etc)
* • Documentar todas las funciones
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
    int verificadorA=0;
    int verificadorB=0;

    while(opcion!=9)
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
                if(verificador(verificadorA,verificadorB)==-1)
                {
                    break;
                }
                else
                {
                    sumo(operandoA,operandoB);
                }
                break;
            case 4:
                if(verificador(verificadorA,verificadorB)==-1)
                {
                    break;
                }
                else
                {
                    resto(operandoA,operandoB);
                }
                break;
            case 5:
                if(verificador(verificadorA,verificadorB)==-1)
                {
                    break;
                }
                else
                {
                    divido(operandoA,operandoB);
                }
                break;
            case 6:
                if(verificador(verificadorA,verificadorB)==-1)
                {
                    break;
                }
                else
                {
                    multiplico(operandoA,operandoB);
                }
                break;
            case 7:
                if(verificador(verificadorA,1)==-1)
                {
                    break;
                }
                else
                {
                    factorial(operandoA);
                }
                break;
            case 8:
                if(verificador(verificadorA,verificadorB)==-1)
                {
                    break;
                }
                else
                {
                    calculoOperaciones(operandoA,operandoB);
                }
                break;
            case 9:
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
        printf("\n\n1. Ingresar 1er operando (A=x)");
        printf("\n2. Ingresar 2do operando (B=y)");
        printf("\n3. Calcular la suma (A+B)");
        printf("\n4. Calcular la resta (A-B)");
        printf("\n5. Calcular la division (A/B)");
        printf("\n6. Calcular la multiplicacion (A*B)");
        printf("\n7. Calcular el factorial (A!)");
        printf("\n8. Calcular todas las operaciones");
        printf("\n9. Salir\n");
    }
    else if(verificadorA!=0 && verificadorB==0)
    {
        printf("\n\n1. Ingresar 1er operando (A=%d)",operandoA);
        printf("\n2. Ingresar 2do operando (B=y)");
        printf("\n3. Calcular la suma (%d+B)",operandoA);
        printf("\n4. Calcular la resta (%d-B)",operandoA);
        printf("\n5. Calcular la division (%d/B)",operandoA);
        printf("\n6. Calcular la multiplicacion (%d*B)",operandoA);
        printf("\n7. Calcular el factorial (%d!)",operandoA);
        printf("\n8. Calcular todas las operaciones");
        printf("\n9. Salir\n");
    }
    else if(verificadorA==0 && verificadorB!=0)
    {
        printf("\n\n1. Ingresar 1er operando (A=x)");
        printf("\n2. Ingresar 2do operando (B=%d)",operandoB);
        printf("\n3. Calcular la suma (A+%d)",operandoB);
        printf("\n4. Calcular la resta (A-%d)",operandoB);
        printf("\n5. Calcular la division (A/%d)",operandoB);
        printf("\n6. Calcular la multiplicacion (A*%d)",operandoB);
        printf("\n7. Calcular el factorial (A!)");
        printf("\n8. Calcular todas las operaciones");
        printf("\n9. Salir\n");    }
    else
    {
        printf("\n\n1. Ingresar 1er operando (A=%d)",operandoA);
        printf("\n2. Ingresar 2do operando (B=%d)",operandoB);
        printf("\n3. Calcular la suma (%d+%d)",operandoA,operandoB);
        printf("\n4. Calcular la resta (%d-%d)",operandoA,operandoB);
        printf("\n5. Calcular la division (%d/%d)",operandoA,operandoB);
        printf("\n6. Calcular la multiplicacion (%d*%d)",operandoA,operandoB);
        printf("\n7. Calcular el factorial (%d!)",operandoA);
        printf("\n8. Calcular todas las operaciones");
        printf("\n9. Salir\n");    }
    return 0;
}



