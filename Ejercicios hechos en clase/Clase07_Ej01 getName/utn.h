#define TRUE 1
#define FALSE 0

int getString(  char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                );
//------------------------------
int getName(    char* msg,
                char* msgError,
                int min,    //cantidad de caracteres
                int max,
                int reintentos,
                char* resultado
                );
//getName difiere de getString en que llama a getString y lo valida
//------------------------------

int isValidName(char* stringRecibido);

//get?
//isValid?
