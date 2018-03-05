// Tarea 4

// 175952
// Karen Peña Albarrán


// Ejercicio 3b
// Modifica la forma en que es llamada `corta_string` dentro de main de modo que devuelva: `verdes`


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