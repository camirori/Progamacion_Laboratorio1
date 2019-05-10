#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employee.h"

//***************************************************************
//Init
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si hay Error [Invalid length or NULL pointer] - (0) si Ok
*
*/
int Employee_inicializar(Employee array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
/** \brief Busca el primer lugar vacio en un array
* \param array Employee Array de Employee
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int Employee_buscarEmpty(Employee array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
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
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Employee Array de Employee
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int Employee_buscarID(Employee array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar los campos de la primer posicion vacia de un array
* \param array Employee Array de Employee
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int Employee_alta(Employee array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(Employee_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].name) == 0 &&
                utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].lastName) == 0 &&
                utn_getFloat("\nSalario: ","\nError",1,sizeof(float),1,&array[posicion].salary) == 0 &&
                utn_getUnsignedInt("\nSector: ","\nError",1,sizeof(int),1,&array[posicion].sector) == 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;
                printf("\nID: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d",
                        array[posicion].idUnico,array[posicion].name,array[posicion].lastName,array[posicion].salary,array[posicion].sector);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}

//*****************************************
/** \brief Borra un elemento del array por ID
* \param array Employee Array de Employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int Employee_baja(Employee array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id);
        if(Employee_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            strcpy(array[posicion].name,"");
            strcpy(array[posicion].lastName,"");
            array[posicion].salary=0;
            array[posicion].sector=0;

            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Employee Array de Employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int Employee_modificar(Employee array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,&id);
        if(Employee_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\nID: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d",
                        array[posicion].idUnico,array[posicion].name,array[posicion].lastName,array[posicion].salary,array[posicion].sector);

                utn_getLetra("\nModificar: A:Nombre B:Apellido C:Salario D:Sector S:Salir","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].name);
                        break;
                    case 'B':
                        utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].lastName);
                        break;
                    case 'C':
                        utn_getFloat("\nSalario: ","\nError",1,sizeof(float),1,&array[posicion].salary);
                        break;
                    case 'D':
                        utn_getUnsignedInt("\nSector: ","\nError",1,sizeof(int),1,&array[posicion].sector);
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

//*****************************************
//Ordenar
/** \brief Ordena por campos lastName y Sector los elementos de un array
* \param array Employee Array de Employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int Employee_ordenar(Employee array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferApellido[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferSector;
    float bufferSalario;
    char bufferNombre[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferApellido,array[i].lastName);
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;
            bufferSector=array[i].sector;
            bufferSalario=array[i].salary;
            strcpy(bufferNombre,array[i].name);

            j = i - 1;
            while ((j >= 0) && (strcmp(bufferApellido,array[j].lastName)<0 || (strcmp(bufferApellido,array[j].lastName)==0 && bufferSector<array[j].sector)))
            {
                strcpy(array[j + 1].lastName,array[j].lastName);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].sector=array[j].sector;
                array[j + 1].salary=array[j].salary;
                strcpy(array[j + 1].name,array[j].name);

                j--;
            }
            strcpy(array[j + 1].lastName,bufferApellido);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].sector=bufferSector;
            array[j + 1].salary=bufferSalario;
            strcpy(array[j + 1].name,bufferNombre);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Employee Array de Employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int Employee_listar(Employee array[], int size)
{
    int retorno=-1;
    int i;

    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0)
            {
                printf("\nID: %d    Nombre: %s  Apellido: %s    Salario: %.2f   Sector: %d",array[i].idUnico,array[i].name,array[i].lastName,array[i].salary,array[i].sector);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Informa total y promedio de los salarios, y cuántos empleados superan el salario promedio.
* \param array Employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se informa
*
*/
int Employee_informarSalario(Employee array[], int size)
{
    int retorno=-1;
    int i;
    int contador=0;
    int acumulado=0;

    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0)
            {
                contador++;
                acumulado+=array[i].salary;
            }
        }
        printf("\nTotal salarios: %d",acumulado);
        acumulado/=contador;
        printf("\nSalario promedio: %d",acumulado);
        contador=0;

        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0 && array[i].salary>acumulado)
            {
                contador++;
            }
        }
        printf("\nCantidad de empleados que superan el salario promedio: %d",contador);
        retorno=0;
    }
    return retorno;
}
