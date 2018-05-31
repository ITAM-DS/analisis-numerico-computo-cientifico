#include<stdio.h>
#include<string.h>
#define MAX_LONG 200

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
	s=s+1;
        i++;
    }
return i;
}
 
int main(void){
    char string1[MAX_LONG];
    char * split;
    int longitud;
    // Se hace la lectura del archivo.txt; el número '100' indica el número de caracteres a leer, me hubiera gustado que fuera variable usando MAX_LONG.
    scanf("%100[0-9a-zA-Z ]", string1);
    // Separamos el string leído por espacios y le aplicamos nuestra función.
    split = strtok (string1, " ");
    while (split != NULL)
    {
      longitud = longitud_string(split);
      printf("longitud %s:  ",split);
      printf("%d\n", longitud);
      split = strtok (NULL, " ");
    }
   // printf("cadena: %s\n", string1);
   // printf("longitud cadena: %d\n", longitud_string(string1));
return 0;
}
