
#include<stdio.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
#include<string.h>

int longitud_string(char *s){//a)
    int i;
    i=0;
    while(*s != '\0'){
        s=s+1;
        i++;
    }
return i;
}

int main(void){
    char string1[] = CADENA_PRUEBA; 
    char string2[MAX_LONG]; 
    char str[100];
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(string1));
    strcpy(string2, "leer libros y revistas"); 
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n\n", longitud_string(string2));
    
    printf("Lectura de STDIN: ---- # \n");
    while (scanf("%s",str)>0)//b)
    {
        printf("Longitud de %s: %d \n", str, longitud_string(str));
    }

return 0;
}
