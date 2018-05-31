#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"

// declaracion
int longitud_string(char *s);

// inicializacion
int longitud_string(char *s){
    int i;
    i=0;
    while(*s != '\0'){
        s=s+1;
        i++;
    }
return i;
}

// main
int main(void){

    printf("\n 1a) \n");
    char string1[] = CADENA_PRUEBA; //definicion y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definicion y declaracion.
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(&string1[0]));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(&string2[0]));
    
    printf("\n 1b) \n");
    char text_input[MAX_LONG];
    char * token_hwk;
    scanf("%[^\n]s",text_input);
    printf ("Texto: %s\n",text_input);
    token_hwk = strtok (text_input," ");

    while (token_hwk != NULL)
    {
      printf ("longitud de %s : %d\n",token_hwk, longitud_string(token_hwk));
      token_hwk = strtok (NULL, " ");
    }
    printf("\n\n");


return 0;
}
	

