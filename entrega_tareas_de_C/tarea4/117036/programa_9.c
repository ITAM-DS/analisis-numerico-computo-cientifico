/*
Eduardo Hidalgo 117036
Tarea 4 c
Ejercicio 3-b*/


/*Modifica la forma en que es llamada la función corta_string dentro de main de modo que devuelva los caracteres: "verdes" (nota que hay un espaico de separación)*/

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
    //Apuntador que indique la posición del espacio en blanco dentro del arreglo de caracteres
    char *apuntarblanco=strstr(s," ");
    //Restamos la adrress del caracter en blanco la primera posicion del arreglo de caracteres "s"
    int posicion=apuntarblanco-s;
    //Para identificar donde empieza la segunda palabara
    //es necesario restar a la longitud total del arreglo "s" el numero de posiciones
    //entre la posicion 0 y la posicion del espacio
    int possegundapalabra=strlen(s)-posicion-1;
    /*En main la funcion corta_string debe ser llamada desde la posicion "0"
    del arreglo "s" mas las posiciones necesarias para encontrar el " "*/
    s=corta_string(s+possegundapalabra);
    printf("%s\n",s);

return 0;
}
