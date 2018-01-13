// gcc main_1c.c funciones_1c.c -o programa_1c.out

#include "definiciones2.h"
int main(void){
    aloja_espacio_e_incializa_matrices();
    imprime_matrices();
    multiplica_matrices();
    imprime_matriz_resultado();
    libera_espacio();

return 0;
}
