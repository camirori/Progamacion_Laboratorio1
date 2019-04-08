
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit, int reintentos);
int isValidInt(int numero,int max, int min);
int pidoIngreso(char *mensaje, int *ingreso);
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit, int reintentos);
int isValidFloat(float min, float max, float valorIngresado);
int solicitoValorFloat(char *mensaje, float *valorIngresado);
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit, int reintentos);
int isValidChar(char min, char max, char valorIngresado);
int solicitoValorChar(char *mensaje, char *valorIngresado);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int reintentos);
int isValidString(char lowLimit, char hiLimit, char *valorIngresado);
void mostrarArray(int size,char* pArray);

