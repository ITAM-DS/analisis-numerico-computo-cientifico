/*
Métodos Numéricos y Optimización
Ixchel G. Meza Chávez

Tarea 4 ejercicio 4 inciso b:

El siguiente programa duplica un string:

b) Escribe una función voltea_string que reciba como parámetro un char * y devuelva un char *
 cuya operación sea devolver un string volteado, así, al llamar voltea_string con el string
  Campos verdes tenemos:

sedrev sopmaC

El prototipo de voltea_string es:

char *voltea_string(char *s);

Utiliza malloc.
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

char *voltea_string(char *s){
	char *p;
	int i, index;
	p = malloc(strlen(s)+1);
	index=0;
	if(p !=NULL){
		for(i=strlen(s)-1;i>=0;i--){
			*(p+index) = *(s+i);
			index++;
		}
		*(p+index)='\0';
	}
	return p;
}

int main(void){
    char s[50] = "Campos verdes";
    char *s_duplicado, *s_volteado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    s_volteado = voltea_string(s);
    printf("%s\n", s_volteado);
    free(s_volteado);
    return 0;
}