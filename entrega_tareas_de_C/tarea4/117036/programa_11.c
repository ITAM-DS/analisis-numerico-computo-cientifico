/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 4-a*/


/*Escribe una funcion voltea_string que reciba un char * y devuelva un char* cuya operacion sea devolver un string volteado*/


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

char *voltea_string(char *s){
  int n,m;
  m=strlen(s);
  char *apuntador;
  apuntador=malloc(m * sizeof(char));
  for(n=0;n<m;n++)
  apuntador[n]=s[m-n-1]; //-1 para no copiar el caracter nulo '\0'
  return apuntador;
}

/*La respuesta está en el uso de apuntadores */
int main(void){
    //apuntador hacia una variable de tipo caracteres
    char *s;
    char *s_duplicado;
    char *s_volteado;
    //Defino la variable s de tipo caracter y la inicializo con el arreglo:
    //"Campos verdes"
    s = "Campos verdes";
    s_duplicado = duplica_string(s);
    s_volteado = voltea_string(s);
    printf("String duplicado: %s\n", s_duplicado);
    printf("String volteado: %s\n", s_volteado);
    free(s_duplicado);
    free(s_volteado);
    return 0;
}
