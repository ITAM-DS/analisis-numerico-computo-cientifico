#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); 
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string(char *s){
    char *invierte_p;
    int i;
    int j = strlen(s);
    invierte_p = malloc(j);
    for(i=0;i<j;i++){
        invierte_p[i] = s[j-1-i]; 
    }
    return invierte_p;
}


int main(void){
    char *s;
    s = malloc(strlen("Campos verdes")+1);
    s = "Campos verdes";
    char *s_duplicado;
    s_duplicado = duplica_string(s);
    printf("a) Modifica para inicializar el string s con un tamaño 50 y sea dinámica su inicialización s.\n\n");
    printf("%s\n", s_duplicado);
    free(s_duplicado);

    printf("\n\nEjercicio b) Devuelve un string volteado\n\n");
    char *al_reves;
    al_reves = voltea_string(s);
    printf("Resultado al revés: %s\n", voltea_string);
    return 0;
}
