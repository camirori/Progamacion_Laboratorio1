#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "utn.h"

//**********************************************************************************************
//Parseo

int Emp_parseo(FILE* pFile, char* bufferA, char* bufferB, char* bufferC, char* bufferD)
{
    int retorno=-1;
    if(pFile!=NULL)
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferA,bufferB,bufferC,bufferD)==4)
            retorno=0;
        if(strcmp(bufferB,"first_name")==0)
            retorno=-1;
    }
    return retorno;
}

//****************************************************************************************
//New

Empleado* Emp_new(void)       //constructor         //nuevo empleado
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado** Emp_reSizeLista(Empleado** pPuntero, int* sizeLista, int i)       //constructor       //nuevo puntero a empleado
{
    if(i==1)
        return (Empleado**) malloc(10*sizeof(Empleado*));
    else if(i>=*sizeLista)
    {
        *sizeLista+=10;
        return (Empleado**) realloc(pPuntero,(*sizeLista)*sizeof(Empleado*));   //chequea si alcanza el tamaño actual, sino agranda
    }
    else
        return pPuntero;
}

Empleado* Emp_newStr(char *id, char *nombre, char *apellido, char *estado)       //constructor         //nuevo empleado con los campos cargados
{
    Empleado* retorno=NULL;
    Empleado* bufferP;
    if(id!=NULL && nombre!=NULL && apellido!=NULL && estado!=NULL)
    {
        bufferP=Emp_new();
        if(bufferP!=NULL)
        {

            if(!Emp_setIdStr(bufferP,id) &&                 //puedo poner retorno=-1,-2,-3 etc para saber cual es el param fuera de rango
                !Emp_setNombre(bufferP,nombre) &&
                !Emp_setApellido(bufferP,apellido) &&
                !Emp_setEstadoStr(bufferP,estado))
            {
                retorno=bufferP;

            }
            /*
            if(!Emp_setNombre(bufferP,nombre))
            {
                printf("\nOk5");
                if(!Emp_setApellido(bufferP,apellido))
                {
                   printf("\nOk6");
                   if(!Emp_setEstadoStr(bufferP,estado))
                   {
                       printf("\nOk7");
                       if(!Emp_setIdStr(bufferP,id))
                            printf("\nOk8");
                            printf("\nId: %d    Nombre: %s  Apellido: %s  Estado: %s",bufferP->id,bufferP->nombre,bufferP->apellido,bufferP->estado);
                            retorno=bufferP;
                   }
                }
            }*/
            else
            {
                Emp_delete(bufferP);
                //realloc array punteros tmb
            }
        }
    }
    return retorno;
}

int Emp_newArchivo(Empleado** pLista, int* index, int* ultimoId, int* sizeLista)
{
    int retorno=-1;
    Empleado* auxPuntero=NULL;
    Empleado** auxPPuntero=NULL;

    FILE *pFile=NULL;
    FILE *pFileBkp=NULL;
    pFile=fopen("data.csv","r");    //direccìon archivo, modo de arpetura
    pFileBkp=fopen("data_bkp.csv","w");     //???

    char arrayBuffers[4][SIZE_STR];        //conviene hacer un array de strings?

    if(pFile!=NULL && pFileBkp!=NULL && index!=NULL && ultimoId!=NULL && sizeLista!=NULL)
    {
        while(!feof(pFile))
        {
            if(Emp_parseo(pFile,arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3])==-1)       //tomo datos del archivo
                continue;

            auxPuntero=Emp_newStr(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
            if(auxPuntero!=NULL)
            {
                auxPPuntero=Emp_reSizeLista(pLista,sizeLista,(*index)+1);                                 //si los datos son validos aumento el size de la lista
                if(auxPPuntero!=NULL)
                {
                    (*index)++;
                    pLista=auxPPuntero;                     //paso &lista de punteros
                    *(pLista+*index)=auxPuntero;             //paso a la lista de punteros &nueva persona
                    *ultimoId=(*(pLista+*index))->id;

                    if((pLista+*index)!=NULL && pLista!=NULL)
                    {
                        printf("\nId: %d    Nombre: %s  Apellido: %s  Estado: %d",(*(pLista+*index))->id,(*(pLista+*index))->nombre,(*(pLista+*index))->apellido,(*(pLista+*index))->estado);
                    }
                }
            }
            else
                printf("\nError validacion");

            if(*index==10)
                    break;
        }
        fclose(pFile);
        fclose(pFileBkp);
    }
    //si se logro cargar todos los datos del archivo retorno=0


    return retorno;
}



int Emp_delete(Empleado* this)       //destructor
{
    int retorno=-1;
    if(this!=NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}


int Emp_setId(Empleado* this, int id)      //para escribir
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Emp_setIdStr(Empleado* this, char *id)      //siempre que el get original no sea char hay que hace un getStr
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=Emp_setId(this,atoi(id));
    }
    return retorno;
}


int Emp_getId(Empleado* this, int* resultado)       //para traer/consultar  int idAux=Emp_getId();
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->id;
        retorno=0;
    }
    return retorno;
}

int Emp_getIdStr(Empleado* this, char* resultado)       //trae el id y lo puedo transformar
{
    int retorno=-1;
    int bufferInt;
    if(this!=NULL && resultado!=NULL)
    {
        Emp_getId(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno=0;
    }
    return retorno;
}

//las -> van a estar unicamente en los set y get

/*
int Emp_setPeso(Empleado* this, float peso)
{
    int retorno=-1;
    if(this!=NULL && peso>=0)
    {
        utn_getFloat("\nPeso: ","\nError",1,3,1,&peso);

        this->peso=peso;
        retorno=0;
    }
    return retorno;
}

int Emp_getPeso(Empleado* this, float* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->peso;
        retorno=0;
    }
    return retorno;
}*/

int Emp_setNombre(Empleado* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Emp_getNombre(Empleado* this, char* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        strcpy(resultado,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Emp_setApellido(Empleado* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {

        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int Emp_getApellido(Empleado* this, char* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        strcpy(resultado,this->apellido);
        retorno=0;
    }
    return retorno;
}


int Emp_setEstado(Empleado* this, int estado)       //transformo TRUE> 1
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->estado=estado;
        retorno=0;
    }
    return retorno;
}

int Emp_setEstadoStr(Empleado* this, char* estado)
{
    int retorno=-1;
    if(this!=NULL && estado!=NULL)
    {
        if(strcmp(estado,"true")==0)
            strcpy(estado,"1");
        else if(strcmp(estado,"false")==0)
            strcpy(estado,"0");

        if(isValidNumber(estado))
            retorno=Emp_setEstado(this,atoi(estado));
    }
    return retorno;
}
/*
int Emp_setEstadoStr(Empleado* this, char* estado)
{
    int retorno=-1;
    if(this!=NULL && estado!=NULL)
    {
        strcpy(this->estado,estado);
        retorno=0;
    }
    return retorno;
}
*/


int Emp_getEstado(Empleado* this, int* resultado)
{
    int retorno=-1;
    if(this!=NULL && resultado!=NULL)
    {
        *resultado=this->estado;
        retorno=0;
    }
    return retorno;
}



/************************************************************************************************************************/
//ABM


//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*//*

int Empleado_buscarEmpty(Empleado** this, int size, int* posicion)                    //cambiar Tipo
{
    int retorno=-1;
    int i;
    if(this!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}*/

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int Empleado_buscarID(Empleado** this, int size, int valorBuscado, int* posicion)                    //cambiar Tipo
{
    int retorno=-1;
    int i;
    int id;
    int estado;

    if(this!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            Emp_getEstado(*(this+i),&estado);
            if(estado==0)        //que significa el estado true?
                continue;

            Emp_getId(*(this+i),&id);
            if(id==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int Tipo_buscarInt(Tipo array[], int size, int valosBuscado, int* posicion)                    //cambiar Tipo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valosBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int Tipo_buscarString(Tipo array[], int size, char* valorBuscado, int* indice)                    //cambiar Tipo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
*/
//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/

int Emp_alta(Empleado** pLista, int* sizeLista, int* ultimoId, int* index)
{
    int retorno=-1;
    Empleado* auxPuntero=NULL;
    Empleado** auxPPuntero=NULL;

    char arrayBuffers[2][SIZE_STR];
    //pLista!=NULL &&
    if( sizeLista!=NULL && ultimoId!=NULL && index!=NULL)
    {
        if( utn_getName("\nNombre: ","\nError",1,SIZE_STR,1,arrayBuffers[0]) == 0  &&    //deberia tomar todos los datos como string?
            utn_getName("\nApellido: ","\nError",1,SIZE_STR,1,arrayBuffers[1]) == 0 )
        {
            auxPuntero=Emp_new();                                                               //creo nueva persona, si el alta no es exitosa cuando lo borro?
            if(!Emp_setId(auxPuntero,(*ultimoId)+1) &&                                       //valido datos y los guardo en el aux
                !Emp_setNombre(auxPuntero,arrayBuffers[0]) &&
                !Emp_setApellido(auxPuntero,arrayBuffers[1]) &&
                !Emp_setEstado(auxPuntero,1))
            {
                if(auxPuntero!=NULL)
                {
                    printf("Error 3");

                    auxPPuntero=Emp_reSizeLista(pLista,sizeLista,(*index)+1);              //si los datos son validos aumento el size de la lista
                    if(auxPPuntero!=NULL)
                    {
                        printf("Error 4");
                        (*index)++;
                        pLista=auxPPuntero;                     //paso &lista de punteros
                        *(pLista+*index)=auxPuntero;             //paso a la lista de punteros &nueva persona
                        *ultimoId=(*(pLista+*index))->id;

                        if((pLista+*index)!=NULL && pLista!=NULL)
                        {
                            printf("\nId: %d    Nombre: %s  Apellido: %s  Estado: %d",(*(pLista+*index))->id,(*(pLista+*index))->nombre,(*(pLista+*index))->apellido,(*(pLista+*index))->estado);
                            retorno=0;
                        }
                    }
                }
            }
            else
                printf("\nError validacion");
        }
    }
    if(retorno!=0)
    {
        printf("\nAlta no exitosa");

    }


    return retorno;
}
/*
Si me pide que uno de los campos tiene que existir en otro array sumo en parametros ese otro array y el tamaño
int posicion(no se usa)
en la validacion (if) sumo Tipo_getInt/String/ID()!=-1 >> !=-1 significa que encontró ese valor
agregar la entidad en define en el c y h
*/

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
/*
int Tipo_baja(Tipo array[], int sizeArray)                                      //cambiar Tipo
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id);          //cambiar si no se busca por ID
        if(Tipo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].varInt=0;                                                               //cambiar campo varInt
            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}
*/
//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
/*
int Tipo_bajaValorRepetidoInt(Tipo array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}
*/


//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
/*
int Tipo_modificar(Tipo array[], int sizeArray)                                //cambiar Tipo
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,&id);         //cambiar si no se busca por ID
        if(Tipo_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                utn_getLetra("\nModificar: A B C D S(salir)","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}
*/
/*
Si me pide que uno de los campos tiene que existir en otro array sumo en parametros ese otro array y el tamaño
int posicion(no se usa)
en la validacion (if) sumo Tipo_getInt/String/ID()!=-1 >> !=-1 significa que encontró ese valor
agregar la entidad en define en el c y h


int buffer;
utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,&buffer);
if(Tipo_buscarID(arrayAux,sizeAux,buffer,&bufferPos)!=-1)
    array[posicion].idArrayAux=buffer;
*/

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
/*
int Tipo_ordenarPorString(Tipo array[],int size)                              //cambiar Tipo
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            strcpy(bufferString,array[i].varString);                      //cambiar campo varString
            bufferInt=array[i].varInt;                                //cambiar campo varInt
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].varString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                strcpy(array[j + 1].varString,array[j].varString);          //cambiar campo varString

                array[j + 1].varInt=array[j].varInt;                        //cambiar campo varInt
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            strcpy(array[j + 1].varString,bufferString);                     //cambiar campo varString

            array[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}
*/
//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Tipo Array de Tipo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
/*
int Tipo_listar(Tipo array[], int size)                      //cambiar Tipo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
*/
