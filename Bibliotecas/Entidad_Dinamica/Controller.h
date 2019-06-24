int controllerFantasma_loadFromText(char* path , LinkedList* pArrayList);
int controllerFantasma_loadFromBinary(char* path , LinkedList* pArrayList);
int controllerFantasma_add(LinkedList* pArrayList, int* ultimoId);
int controllerFantasma_edit(LinkedList* pArrayList);
int controllerFantasma_remove(LinkedList* pArrayList);
int controllerFantasma_list(LinkedList* pArrayList);
int controllerFantasma_sort(LinkedList* pArrayList);
int controllerFantasma_saveAsText(char* path , LinkedList* pArrayList);
int controllerFantasma_saveAsBinary(char* path , LinkedList* pArrayList);
