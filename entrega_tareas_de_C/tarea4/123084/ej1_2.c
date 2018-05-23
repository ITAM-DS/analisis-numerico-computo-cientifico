#include<stdio.h>

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        i++;
        s = s+1;
    }
return i;
}

void main(){

	char str [100];
	
	while (scanf("%s",str)>0){
		  //prueba paso a paso
        printf("el tamano de %s:  es %d\n", str, longitud_string(str));
    }
}