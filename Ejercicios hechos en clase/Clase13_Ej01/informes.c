//INFORMAR Y LISTAR:
//A) Informar el Total general y Promedio diario de las solicitudes a pr�stamo de los libros.




//B) Informar la cantidad de d�as cuya solicitud a pr�stamo NO superan el promedio del �tem anterior.


//C) Listar todos los socios que solicitaron el pr�stamo de un libro determinado.
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


//D) Listar todos los libros que fueron solicitados a pr�stamo por un socio determinado.

//E) Listar el/los libro/s menos solicitado/s en pr�stamo.          //!!!! igual a max pero comparo < en lugar de >, inicializo con el resultado del primer elemento

//F) Listar el/los socios que realiz�/realizaron m�s solicitudes a pr�stamo.
//G) Listar todos los libros solicitados a pr�stamo en una fecha determinada.
//H) Listar todos los socios que realizaron al menos una solicitud a pr�stamo en una fecha determinada.
//I) Listar todos los libros ordenados por T�tulo (descendente), utilizando el m�todo de burbujeo m�s eficiente.
//J) Listar todos los socios ordenados por Apellido (ascendente), utilizando el m�todo de inserci�n.
