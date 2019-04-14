int getString(  char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                );
int utn_getName(    char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                );
int isValidName(char* stringRecibido);
int utn_getNumero(  char* msg,
                    char* msgError,
                    int minSize,    //cantidad de caracteres
                    int maxSize,
                    int min,
                    int max,
                    int reintentos,
                    int* input);
int isValidNumber(char* stringRecibido);


