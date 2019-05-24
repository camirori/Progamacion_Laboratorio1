#include <stdio.h>
#include <stdlib.h>

int main()
{
    //abrir archivo: trae info que me va a permitir recorrerlo
    //en los archivos windows se agrega una letra para indicar si el archivo es binario, en linux es indistinto
    //FILE es un tipo de dato
    //Cuando se abre un archivo hay que cerrarlo lo antes posible, no se deja abierto. Traigo a RAM lo que necesito y lo cierro
    //se copia el archivo .csv en la carpeta del proyecto
    char bufferStr[4096];
    FILE *pFile=NULL;
    FILE *pFileBkp=NULL;
    pFile=fopen("data.csv","r");    //direccìon archivo, modo de arpetura
    pFileBkp=fopen("data_bkp.csv","w");     //si no existe lo crea
    /*
    if(pFile!=NULL && pFileBkp!=NULL)                 //puede no abrirlo por falta de permisos, porque esta siendo usado por otra app, no existe, etc
    {
        while(!feof(pFile))                    //feof return 1/V cuando termina el archivo
        {
            fscanf(pFile,"%s",bufferStr);       //scanf lee hasta encontrar un enter
            fprintf(pFileBkp,"\n%s",bufferStr);           //scanf descarta el salto de linea
        }
        fclose(pFile);
        fclose(pFileBkp);
    }*/

    //Parseo: buscar hasta donde cortar y pasar esa secciòn a una variable, por ej las comas
    char bufferId[4096];                //siempre que traigo algo de un archivo de texto lo voy a guardar en un bufferStr
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferEstado[4096];

    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);       //mascara     ^, > toma todo menos las comas     en los archivos va a haber un delimitador que separe los datos , y uno q separe las entidades \n
            //empleado_newEmpleado que guarda los datos en un nuevo empleado y devuelve un puntero
            printf("\n%s",bufferApellido);         //%significa que tiene que ser interpretado y guardado en una variable, sino solo la interpreta y la descarta
        }                                                  //El separador tiene que ser un caracter que se q no voy a usar para los datos
        fclose(pFile);
        fclose(pFileBkp);
    }

    return 0;
}

/*
Archivos:
-De texto
-Binario

Binarios:
    ventajas:
        Bajar memoria al disco > por ej recorrer un array y pasarlo al archivo



Tendencia a representar info como texto ya que no hay tanto enfasis en ahorrar espacio
Los archivos se usan para soluciones de configuracion, para otras cuestiones se usan en la realidad base de datos
Un proyecto de codeblocks es un archivo de texto plano
Hay minimas variaciones de un lenguaje a otr sobre como usar archivos




El new deberia recibir los parametros como string
Tmb hace una version de los get+set que reciba el parametro como string

*/
