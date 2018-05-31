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
    int size;
    char *fun_volt;
    fun_volt = malloc(strlen(s)+1);
    size= strlen(s)-1;

    int j;
    while(1){
        fun_volt[j] = s[size];
        if(s[j] == '\0') break;
        j++;    
        size--;
    }

    return fun_volt;
}


int main(void){
    char *s;
    char *str_2 = "Campos grises";
    char *string_v;
    s = malloc(strlen(str_2)+1);
    strcpy(s, str_2);
    char *s_duplicado;
    char *s_fun_volt;
    s_fun_volt = voltea_string(s);
    s_duplicado = duplica_string(s);
    printf("%s\n", s_fun_volt);
    free(s_duplicado);
    free(s);
    return 0;
}

