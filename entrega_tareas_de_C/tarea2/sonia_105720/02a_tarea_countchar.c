// Tarea 2
// Sonia Mendizabal  

// 2. Modifica main para que sólo se llame una vez a la función getchar()

// 3. Utiliza getchar para escribir un programa que cuente el número de caracteres.
// Al dar enter (salto de línea) el programa termina.

#include <stdio.h>
#include <string.h>

int main(void){
    char str[100];
    int c, n = 0, len;
    
    //while( (c = getchar()) != EOF){   
    while( (c = getchar()) != '\n'){
        str[n] = c;
        //printf("str[%d]: %c\n", n, str[n]); 
        //printf("char ");
        //putchar(c);
        //printf("\n");
        n++;
        
    } 
    len = strlen(str);
    printf("%d\n", len);
    //printf("length total: %d\n", len);
    //printf("count final %d\n", n);
    printf("\n");

return(0);
}
