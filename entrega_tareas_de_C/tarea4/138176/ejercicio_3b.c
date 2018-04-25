//Daniel Sharp 138176
// Ejercicio 3B

#include<stdio.h>
char *corta_string(char *apuntador){
    apuntador=apuntador+1;
    return apuntador;
}

int main(void){
    char *s="Campos verdes";
    // Aplicamos la función de corta string hasta que el último valor cortado sea un espacio
    while(s[-1] != ' ')
      s=corta_string(s);
    printf("%s\n",s);

return 0;
}
