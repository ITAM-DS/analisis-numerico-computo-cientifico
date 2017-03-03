// Tarea 4

// 105720
// Sonia Mendizabal Claustro



// Ejercicio 4a
// Modifica el programa para que en lugar de inicializar el string `s` con un tamaño `50` 
// sea dinámica su inicialización, es decir, que no tengas que escribir `50` o algún valor 
// definido para el tamaño del string `s`.



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *duplica_string(char *s){  
    char *p;
    
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    
    return p;
}

int main(void){
    char *s = malloc( sizeof(char) * sizeof("Campos verdes")) ;
    char *s_duplicado;
    
    s = "Campos verdes";
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    
    free(s);
    free(s_duplicado);
    return 0;
}

