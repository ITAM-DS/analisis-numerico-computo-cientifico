#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

#include<stdio.h>
#include<string.h>
 
 int longitud_string(char *s){
     int i;
     i=0;
     while(*s != '\0'){
         i++;
         s++;
       }
 return i;
 }
 

	
 int main(void){
     char string[MAX_LONG];
     while(scanf("%s",string)==1){
     	printf("longitud %s: %d\n", string, longitud_string(string));
     }
   return 0;
 }
