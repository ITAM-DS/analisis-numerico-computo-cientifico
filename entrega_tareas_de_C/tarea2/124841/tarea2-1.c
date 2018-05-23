/*Se debe declarar c como int porque getchar() representa con codigo ascii todos los caracteres que se le puedan dar, es decir con numeros enteros, y EOF significa end of file y se representa con -1*/
#include <stdio.h>
main(void){
    int c;
    while(c=getchar() != EOF){ 
      putchar(c);
        
         
          
    } 
}
