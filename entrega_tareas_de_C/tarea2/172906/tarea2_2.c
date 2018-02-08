
/*********************************** Arturo Gonzalez Bencomo - 172906 *****************************************/

/**************************************************************************************************************
Instrucciones:
2.  Modifica main para eliminar la línea:

    c = getchar();

antes del while y hacer el llamado a getchar en la condición del while.
****************************************************************************************************************/

#include <stdio.h>

int main(void){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
    return 0; 
}
