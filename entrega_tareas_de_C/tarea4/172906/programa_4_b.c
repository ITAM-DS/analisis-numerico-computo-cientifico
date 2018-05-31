/* 
Arturo Gonzalez Bencomo 172906

Tarea4

Ejercicio4_a
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *duplica_string(char *s);
char *voltea_string(char *s);

int main(void){
    char s[] = "Campos verdes";
    char *s_duplicado,*s_volteado;

    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    
    s_volteado = voltea_string(s);
    printf("%s\n", s_duplicado);
    free(s_volteado);       

    return 0;
}

char *duplica_string(char *s){  
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string(char *str){  
    int length= strlen(str);
    char *t2 = (char*)malloc((length+1) * sizeof(char));
    for(int i=0;i<length;i++)
    {
      t2[(length-1)-i]=str[i];      
    }
    t2[length] = '\0';
    return t2;
}

