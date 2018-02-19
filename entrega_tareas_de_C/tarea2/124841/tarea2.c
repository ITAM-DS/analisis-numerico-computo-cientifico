#include <stdio.h>
main(void){
    int n,c;
    n=0;
   c=getchar();
    while(c != EOF && c != '\n'){
      n++;  
     c=getchar();
    } 
printf("Numero de caracteres:%d\n", n);
}

/*Se debe declarar c como int porque getchar() representa con codigo ascii todos los caracteres que se le puedan dar, es decir con numeros enteros, y EOF significa end of file y se representa con -1*/

