#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
/*

Estructuras/entidades:
Pantalla
    int idPantalla
    int isEmpty
    char nombre[]
    char direccion[]
    char tipo []
    float precio

Publicidad
    int idPublicidad
    int isEmpty
    char cuit[]
    int dias
    char archivo[]
    int idPantalla


Entidad extra si se contratan varias pantallas por publicidad (no en este caso)
    int idPantalla
    int idPublicidad


Siempre:
    Alta, baja, modificacion
    init array
    Buscar vacio
    print array
    buscar id

*/
