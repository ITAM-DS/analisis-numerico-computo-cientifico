#include <stdio.h>
#include <string.h>
#define MAX_LONG 1000

int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0')
        i++;
        s=s+1;
return i;
}
 
int main(void){
    char input[MAX_LONG];
    //scanf("%s", input);
    //input_point = input;
     // if (*s == '\n')
     //    break; /* Blank line */
     // else
    // printf("%s es el string", input_point);
    while(scanf("%s", input) != EOF){
        printf("%s es el string con longitud %d \n", input, longitud_string(input));
    }
        //input = input+1;
        //printf(" que tiene longitud %i \n", longitud_string(input_point)); /* The input was not a blank line */
    //}
        // char string1[] = CADENA_PRUEBA; //definición y declaracion de variable e inicializacion.
        // char string2[MAX_LONG]; //definición y declaracion.
        // printf("cadena: %s\n", string1);
        // printf("longitud cadena: %d\n", longitud_string(string1));
        // strcpy(string2, "leer libros y revistas"); //inicializacion de string2
        // printf("cadena2: %s\n", string2);
        // printf("longitud cadena: %d\n", longitud_string(string2));
    return 0;
}
