//Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Tipo Array de Tipo
* \param arrayB Tipo Array de Tipo
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Employee_listar(Employee array[], int size)
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
                printf("\n ID: %d   Nombre: %s      Apellido: %s    Salario: %f     Sector: %d",array[i].idUnico,array[i].name,array[i].lastName,array[i].salary,array[i].sector);
                contador++;
                acumulado+=array[i].salary;
            }
        }
        printf("\Total salarios: %d",acumulado)
        acumulado/=contador;
        printf("\Salario promedio: %d",acumulado)
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
