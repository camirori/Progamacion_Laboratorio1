
int getInt(int* input,char *message,char *eMessage, int lowLimit, int hiLimit, int reintentos);
int isValidInt(int numero,int max, int min);
int pidoIngresoInt(char *mensaje, int *ingreso);
int getFloat(float* input,char* message,char* eMessage, float lowLimit, float hiLimit, int reintentos);
int isValidFloat(float valorIngresado, float min, float max);
int pidoIngresoFloat(char *mensaje, float *valorIngresado);
int getChar(char* input,char* message,char* eMessage, char lowLimit, char hiLimit, int reintentos);
int isValidChar(char valorIngresado, char min, char max);
int pidoIngresoChar(char *mensaje, char *valorIngresado);
int getString(char* input,char* message,char* eMessage, int lowLimit, int hiLimit, int reintentos);
int pidoIngresoString(char *mensaje, char *valorIngresado);
int isValidString(char *valorIngresado, char lowLimit, char hiLimit);
int getArrayInt(int* input,char *message,char *eMessage, int lowLimitInt, int hiLimitInt, int lowLimitArray, int hiLimitArray, int reintentos);
int isValidArrayInt(int *valorIngresado, int lowLimit, int hiLimit);
void mostrarArray(int size,int* pArray);

