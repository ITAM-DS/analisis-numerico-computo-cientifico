#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *voltea_string(char *s){

long int i;
//char intermediate[strlen(s)];
char *intermediate;
intermediate=malloc(sizeof(strlen(s))+1);

    for (i=strlen(s);0<=i;i--){
        *(intermediate+(strlen(s)-i))=*(s+(i-1));

    }

intermediate[strlen(s)]='\0';
printf("%s\n",intermediate);

}

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}
int main(void){

    char *s;
    char *s_duplicado;
    s=malloc(sizeof(char)*strlen(s));

    printf("Enter tu string (los espacios deben ser representado por _ ) : ");
    scanf("%s",s);

    
    printf("\n----Duplicado----\n\n ");
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    printf("\n");

    printf("----Volteado----\n\n");
    voltea_string(s);
    printf("\n");

    free(s_duplicado);
    free(s);

    return 0;
}