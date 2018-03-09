#include<stdio.h>
char *corta_string(char *apuntador){
	int i=0;
	char c;
	char *error="Error: El string debe de ser de longitud mayor a 1";
	while((c=*(apuntador+i)) != '\0') i++;
	if(i==1){return error;}
    else {apuntador=apuntador+1;}
    return apuntador;
}

void corta_espacio(char *apuntador){
    int i = 1;
    int flag = 0;
    char c;
    while((c=*(apuntador+i)) != '\0'){
        if(flag==1) printf("%c", c);
        if(c==' ') flag=1;
        i++;  
    } 
}

int main(void){
    printf("\na) La funcion corta_string no hace un chequeo si el string que recibe\ncomo parámetro debe de tener al menos un caracter.");
    printf(" Modifica esta función de modo que haga este chequeo:\n\n");
    char *s="Campos verdes";
    char *er="c";
    printf("\nSe evalúa el string: Campos Verdes\n");
    s=corta_string(s);
    printf("Resultado: %s\n\n",s);
    printf("Se evalúa el string: c\n");
    er=corta_string(er);
    printf("Resultado: %s\n", er);

    printf("\n\nb) Cómo modificas la forma en que es llamada corta_string dentro de main de modo que devuelva: verdes ?? (hay un espacio antes del string 'verdes').\n\n");
    s="Campos verdes";
    printf("Resultado: ");
    corta_espacio(s);
    printf("\n");
 
return 0;
}
