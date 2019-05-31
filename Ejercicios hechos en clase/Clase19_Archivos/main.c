#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=350;
    int b=33;
    int c=352;
    int d=27;

    FILE* pf=fopen("prueba.txt","w+");

    if(pf!=NULL)
    {
        fprintf(pf,"%d,%d\n",a,b);
        fprintf(pf,"%d,%d\n",c,d);

        fwrite(&a,sizeof(a),1,pf);

        //printf(pf,"%s,%d,%d\n",p.nombre,p.edad,p.dni);
        scanf(pf,"%d,%d\n",a,b);
        fclose(pf);
    }


    return 0;
}


/*
Preguntas parcial:
tamaño de un dato guardado de diferentes formas (texto, binario, hexa)
diferencia entre fprintf y fwrite


el parseo es necesario cuando el archivo esta en modo texto, no cuando es binario

f() parser param: puntero archivo, array
*/


