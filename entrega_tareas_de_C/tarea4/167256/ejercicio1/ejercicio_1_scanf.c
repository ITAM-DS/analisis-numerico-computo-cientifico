#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
int longitud_string(char s[]){
    int i;
    i=0;
    while(*s != '\0'){
      s=s+1;
      i++;
    }
return i;
}
 
int main(void){
    char string1[MAX_LONG]; //definición y declaracion de variable e inicializacion.
    while(scanf("%s", string1)>0){
      printf("longitud cadena %s: %d\n",string1, longitud_string(string1));
    }
return 0;
}
