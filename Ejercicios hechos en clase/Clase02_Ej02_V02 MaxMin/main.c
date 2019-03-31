#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_NUMEROS_A_INGRESAR 5

int ingresoNumeros(void);
int maxMin(int numeroIngresadoF, int *maximoIngresadoF, int *minimoIngresadoF);


int main()
{
    ingresoNumeros();

    return 0;
}

int ingresoNumeros(void)
{
    int i;
    int numeroIngresado;
    int maximoIngresado;
    int minimoIngresado;

    for(i=0; i<CANTIDAD_NUMEROS_A_INGRESAR; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numeroIngresado);
        if(i==0)
        {
            maximoIngresado=numeroIngresado;
            minimoIngresado=numeroIngresado;
        }
        maxMin(numeroIngresado,&maximoIngresado,&minimoIngresado); //cuando llamo la funciòn indico los argumentos q van a reemplazar a los parametros

    }
    printf("El maximo ingresado es: %d\n",maximoIngresado);
    printf("El minimo ingresado es: %d\n",minimoIngresado);

    return 0;
}

int maxMin(int numeroIngresadoF, int *maximoIngresadoF, int *minimoIngresadoF) //el asterisco permite modificar el valor de las variables que doy como argumento
{
    if(numeroIngresadoF>*maximoIngresadoF)
    {
        *maximoIngresadoF=numeroIngresadoF;
    }
    if(numeroIngresadoF<*minimoIngresadoF)
    {
        *minimoIngresadoF=numeroIngresadoF;
    }

    return 0;
}
