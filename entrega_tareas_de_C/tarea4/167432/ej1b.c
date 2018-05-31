#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
	s = s+1;}
return i;
}
 
int main(void){
char string[MAX_LONG];
while(scanf("%s",&string)==1){
printf("Longitud de %s es: %d\n",string,longitud_string(string));
}
return 0;
}
