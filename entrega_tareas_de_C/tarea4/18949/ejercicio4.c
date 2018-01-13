/*
 * ejercicio4.c
 *
 *  Created on: Mar 2, 2017
 *      Author: Javier Quiroz
 */
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


char * voltea(char *cadena){
    int len;
    char * buffer;
    char * inicio =  cadena;
    char * start;
    len = strlen(cadena);
    buffer = (char * )malloc(len);
    start = buffer;
    char *p = inicio +len-1;
    while(inicio <= p ){
    	*buffer = *p;
    	p--;
    	buffer++;
     }
    *buffer = '\0';
    return start;
}
int main(void){
/*
 * a) a) Modifica el programa para que en lugar de inicializar el string s
 * con un tamaño 50 sea dinámica su inicialización, es decir, que no tengas
 * que escribir 50 o algún valor definido para el tamaño del string s. Utiliza malloc.
 *
 * Respuesta: Esto se logra utilizando la funcion duplica_string, ya propocionada. Esta
 * ya utiliza malloc
 *
 *
 * b) Escribe una función voltea_string que reciba como parámetro un char * y devuelva
 * un char * cuya operación sea devolver un string volteado, así, al llamar voltea_string
 * con el string Campos verdes tenemos: sedrev sopmaC
 * El prototipo de voltea_string es:
 * char *voltea_string(char *s); Utiliza malloc.
 *
 * Respuesta: Se programó esta funcion utilizando apuntadore y alojamiento dinamico de memoria, con
 * logica parecida a la del ejercio 2 de esta misma tarea
 *
 */
    char *s = duplica_string("Campos verdes");
    char *s_duplicado;
    char *d = "Campos verdes";
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    printf("%s\n", voltea(d));

    return 0;
}

