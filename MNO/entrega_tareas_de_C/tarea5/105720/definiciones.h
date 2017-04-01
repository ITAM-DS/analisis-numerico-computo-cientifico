// Tarea 5

// 105720
// Sonia Mendizabal Claustro


// Ejercicio c
// Modifica el archivo funciones.c para que alojes e inicialices a
// las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. 
// Modifica main.c para que llame a una función dentro del archivo funciones.c 
// que inicialice y aloje a las matrices anteriores y llame a otra función 
// para que las desaloje una vez hecha la multiplicación (usa free)




#define NUM_REN_MAT1 3
#define NUM_COL_MAT1 2
#define NUM_REN_MAT2 2
#define NUM_COL_MAT2 3 

void imprime_matrices(void);
void imprime_matriz_resultado(void);
void multiplica_matrices(void);


// Definición de funciones que alojan y liberan las variable
void aloja_espacio_e_incializa_matrices(void);
void libera_espacio(void);