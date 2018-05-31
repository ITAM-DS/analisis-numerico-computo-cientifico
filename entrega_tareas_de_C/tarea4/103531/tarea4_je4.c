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
    char texto[] = "hola que tal, tarea ejercicio 4";//este es el texto que vamos  a recibir
    char *s;
    s  = (char *)  malloc(sizeof(texto));//ya no definimos un valor fijo para inicializar s, 
					 //ahora utilizamos la funcion malloc que asigna  el espacio de memoria
    strcpy(s,texto);//una vez asignado, actualizamos el valor
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    return 0;
}
