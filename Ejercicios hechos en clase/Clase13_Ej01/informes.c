//INFORMAR Y LISTAR:
//A) Informar el Total general y Promedio diario de las solicitudes a préstamo de los libros.




//B) Informar la cantidad de días cuya solicitud a préstamo NO superan el promedio del ítem anterior.


//C) Listar todos los socios que solicitaron el préstamo de un libro determinado.
int Socios_listar(Prestamos arrayPrestamos[], int size, Socios arraySocios[], int sizeSocios)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferPosicion;

    if(arrayPrestamos!=NULL && size>=0)
    {
        utn_getSignedInt("\nCodigo libro: ","\nError",1,sizeof(int),1,2,1,&bufferID);
        for(i=0;i<size;i++)
        {
            if(arrayPrestamos[i].isEmpty==1 && arrayPrestamos[i].idLibro!=bufferID)
                continue;
            else
                Socios_buscarID(arraySocios,sizeSocios,bufferID,&bufferPosicion);
                printf("\nCodigo de socio: %d\nApellido: %s\nNombre: %s\nSexo: %c\nTelefono: %s \nEmail: %s\nFecha: %s",
                   arraySocios[bufferPosicion].idUnico,arraySocios[bufferPosicion].apellido,arraySocios[bufferPosicion].nombre,arraySocios[bufferPosicion].sexo,arraySocios[bufferPosicion].telefono,
                   arraySocios[bufferPosicion].email,arraySocios[bufferPosicion].fechaAsociado);
        }
        retorno=0;
    }
    return retorno;
}


//D) Listar todos los libros que fueron solicitados a préstamo por un socio determinado.

//E) Listar el/los libro/s menos solicitado/s en préstamo.          //!!!! igual a max pero comparo < en lugar de >, inicializo con el resultado del primer elemento

//F) Listar el/los socios que realizó/realizaron más solicitudes a préstamo.
//G) Listar todos los libros solicitados a préstamo en una fecha determinada.
//H) Listar todos los socios que realizaron al menos una solicitud a préstamo en una fecha determinada.
//I) Listar todos los libros ordenados por Título (descendente), utilizando el método de burbujeo más eficiente.
//J) Listar todos los socios ordenados por Apellido (ascendente), utilizando el método de inserción.
