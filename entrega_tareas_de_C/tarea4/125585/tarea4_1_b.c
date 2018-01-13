#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        s=s+1;
        i++;         
    }//while
return i;
}
 
int main(void){
    char string_input[200];
    while(scanf("%s",string_input)>0)
        printf("Longitud: %s, %d \n", string_input,longitud_string(string_input));
return 0;
}