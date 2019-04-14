#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[7]={'H','O','L','A','\0'}; // igual a char nombre[257]="HOLA"; el compilador lo convierte en el 1ro
    char nombre2[7]="HOLA";
    //NO! > nombre="Juan";

    //Para copiar el valor de una variable a otra no uso =, sino strncpy
     // sizeof(nombre) indica que tamaño tiene reservado en memoria ese array
    strncpy(nombre,nombre2,sizeof(nombre)); // 1. Destino, 2. origen, 3.le paso el tamaño de destino


    //No se usa scanf
    fgets(nombre,sizeof(nombre),stdin); //1. donde quiero dejar la info 2. Tamaño maximo 3.puntero al archivo
    printf("\n%s",nombre);

    strlen();
    strcmp(); // comparacion, no existe >,<,==,!=

    return 0;
}
