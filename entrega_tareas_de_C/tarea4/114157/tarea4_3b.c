# include <stdio.h>
# include <string.h>
# include <ctype.h> 

char *corta_string(char *apuntador){
    apuntador = apuntador + 1;
    return apuntador;
}

int main(void){
    int len, i ;
    char *s="Campos verdes";  

    // Hasta que el primer elemento sea  blankspace
    while( !isspace(s[0]) ){ 
        s = corta_string(s);
    }
    printf("%s\n", s);
return 0;
}