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

    printf("\n a) ----------- \n");
    char string1[] = CADENA_PRUEBA; //definicion y declaracion de variable e inicializacion.
    char string2[MAX_LONG]; //definicion y declaracion.
    printf("cadena: %s\n", string1);
    printf("longitud cadena: %d\n", longitud_string(&string1[0]));
    strcpy(string2, "leer libros y revistas"); //inicializacion de string2
    printf("cadena2: %s\n", string2);
    printf("longitud cadena: %d\n", longitud_string(&string2[0]));
    
    printf("\n b) ----------- \n");

    char texto[MAX_LONG];
    char * token;

    scanf("%[^\n]s",texto);
    printf ("Texto: %s\n",texto);

    token = strtok (texto," ");

    while (token != NULL)
    {
      printf ("Longitud %s : %d\n",token, longitud_string(token));
      token = strtok (NULL, " ");
    }
    printf("\n\n");


return 0;
}
	


