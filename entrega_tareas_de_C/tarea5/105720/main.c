// Tarea 5

// 105720
// Sonia Mendizabal Claustro


// Ejercicio c
// Modifica el archivo funciones.c para que alojes e inicialices a
// las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. 
// Modifica main.c para que llame a una función dentro del archivo funciones.c 
// que inicialice y aloje a las matrices anteriores y llame a otra función 
// para que las desaloje una vez hecha la multiplicación (usa free)



# include "definiciones.h"

int main(void){

    aloja_espacio_e_incializa_matrices();
    imprime_matrices();
    multiplica_matrices();
    imprime_matriz_resultado();
    libera_espacio();
    
return 0;
}