/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 4-a*/


/*Modifica el programa para que en lugar de inicializar el string s con un tamaño de 50, sea dinamica su inicalizacion, que no tengas que escribr 50 o algun valor para el tamaño del string s*/


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
/*La respuesta está en el uso de apuntadores */
int main(void){
    //apuntador hacia una variable de tipo caracteres
    char *s;
    //Defino la variable s de tipo caracter y la inicializo con el arreglo:
    //"Campos verdes"
    s = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    return 0;
}
