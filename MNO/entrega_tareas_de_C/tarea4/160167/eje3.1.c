//Ejercicio3 By Ricardo Lastra
//Segunda parte
//b) Cómo modificas la forma en que es llamada corta_string dentro de main de modo que devuelva: verdes ?? (hay un espacio antes del string "verdes").


#include<stdio.h>
#include<string.h>
char *corta_string(char *apuntador){
    if(strlen(apuntador) != '\0')
	return apuntador + 1;
	else
		return "Error, introduce algun caracter!!!\n";
}

int main(void){
    char *s="Campos Verdes";
	while(*s!= ' '){
		s=corta_string(s);
	}
    printf("%s\n",s);

return 0;
}
