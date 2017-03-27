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
    /*Como se trata de almacenar memoria para la variable podemos considerar que un string
    es un array de caracteres por lo que para saber la memoria necesaria podemos considerar
    la memoria necesaria para un caracter y multiplicarla por el número de caracteres en el string.*/

    /*ESTA FUNCION ESCUPE LO QUE QUIERO PERO DA UN ERROR... NO ENTIENDO POR QUE*/
    double memoria_char=sizeof(char), longitud_string=(sizeof("Campos verdes")+1);
    char *s= malloc(memoria_char*longitud_string);
    char *s_duplicado;
    s="Campos verdes";
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s);
    free(s_duplicado);
    return 0;
}