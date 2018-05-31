#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Prototipo de funciones */
char voltea_string(char);
char duplica_string(char);

// Funcion para duplicar string
char *duplica_string(char *s2){
    char *p; // inicio un apuntador
    p = (char*) malloc(strlen(s2)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL){
		strcpy(p,s2);//copiamos el string
	}
    return p;
}


// Escribir una función voltea_string que reciba como parámetro char * y devuelva char *
// que regrese la frase volteada. 
char *voltea_string(char* palabra) {
  char *p;
  // define the char malloc
  // que sea del tamaño de la palabra normal
  p = (char*) malloc(strlen(palabra)+1);
  if(p!=NULL){
	  p=palabra;
  }
  // almacena la primera direccion
  char *a = p; 
  char *b = a + strlen(p) -1; // la última dirección
  char temp;
  while (b>a){
    temp = *a;
    *a++ = *b;
    *b-- = temp;

  }
  return p;
}

int main(void){
    char *s;
    char *s2;
    char *s_duplicado;
    char *flip;
    s = "Campos verdes";

    // define the char malloc
    s2 = (char*) malloc(strlen(s)+1);
    if(s2!=NULL){
	    strcpy(s2,s);
    }
    // duplica el string
    s_duplicado = duplica_string(s2);
    printf("%s\n", s_duplicado);
    // deallocates the memory previously allocated by malloc
    free(s_duplicado);

    flip = voltea_string(s2);
    printf("%s\n", flip);
    free(flip);
    return 0;
}
