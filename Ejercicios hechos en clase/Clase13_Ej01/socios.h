#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#define TEXT_SIZE 31
#define TEL_SIZE 16

typedef struct
{
    int idUnico;         //siempre
    int isEmpty;            //siempre
    //-----------------
    char apellido[TEXT_SIZE];
    char nombre[TEXT_SIZE];
    char sexo;
    char telefono[TEL_SIZE];
    char email[TEXT_SIZE];
    char fechaAsociado[TEXT_SIZE];

}Socios;


#endif // SOCIOS_H_INCLUDED

/*
Socios:
 Código de Socio (autoincremental)
 Apellido (máximo 31 caracteres) Validar
 Nombre (máximo 31 caracteres) Validar
 Sexo ( F | M ) Validar
 Teléfono (máximo 16 caracteres) Validar
 eMail (máximo 31 caracteres) Validar
 Fecha de asociado Validar día, mes y año
*/
