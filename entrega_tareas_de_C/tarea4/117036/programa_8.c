/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 3-a*/


/*Modifica la función corta_string para que realice un chequeo sobre si el string que recibe como parametro debe tener al menos un caracter*/

#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
if(strlen(apuntador)>0){
    apuntador=apuntador+1;
    return apuntador;
  } else
  printf("Error: El texto ingresado no contiene caracteres \n");
}

int main(void){
    char *s="Campos verdes";
    s=corta_string(s);
    printf("%s\n",s);

return 0;
}
