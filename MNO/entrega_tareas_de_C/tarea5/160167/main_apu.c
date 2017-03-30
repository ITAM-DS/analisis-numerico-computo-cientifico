//Modifica main.c para que llame a una función dentro del archivo funciones.c que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa free):

#include"definiciones_apu.h"
int main(void){
    aloja_espacio_e_inicializa_matrices();
    imprime_matrices();
    multiplica_matrices();
    imprime_matriz_resultado();
    libera_espacio();
return 0;
}
