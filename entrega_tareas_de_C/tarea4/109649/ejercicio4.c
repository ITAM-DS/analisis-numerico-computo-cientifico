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
    char *inv_s;
    int n;
    int i = strlen(s);
    inv_s = malloc(i);
    for(n=0;n<i;n++){
        inv_s[n] = s[i-1-n]; 
    }
    return inv_s;
}


int main(void){
    char *s;
    s = malloc(strlen("Campos verdes")+1);
    s = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("a) Modifica el programa para que en lugar de inicializar el string s con un tamaño 50 sea dinámica su inicialización, es decir, que no tengas que escribir 50 o algún valor definido para el tamaño del string s.\n\n");
    printf("%s\n", s_duplicado);
    free(s_duplicado);

    printf("\n\nb) Escribe una función voltea_string que reciba como parámetro un char * y devuelva un char * cuya operación sea devolver un string volteado, así, al llamar voltea_string con el string Campos verdes tenemos: sedrev sopmaC\n\n");
    char *volteado;
    volteado = voltea_string(s);
    printf("Resultado volteado: %s\n", volteado);
    return 0;
}