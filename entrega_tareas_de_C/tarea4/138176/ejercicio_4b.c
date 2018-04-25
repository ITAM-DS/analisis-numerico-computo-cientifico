// Daniel Sharp 138176
// Ejercicio 4B

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *duplica_string(char *s){
    char *p;
    p = malloc(strlen(s)+1); /* sumamos uno para almacenar el caracter '\0'*/
        if(p!=NULL)
        strcpy(p,s);
    return p;
}

char *voltea_string(char *s);


int main(void){
    char s[50] = "Campos verdes";
    char *s_duplicado, *s_volteado;
    s_duplicado = duplica_string(s);
    printf("%s\n", s_duplicado);
    free(s_duplicado);
    s_volteado = voltea_string(s);
    printf("%s\n", s_volteado);
    free(s_volteado);
    return 0;
}

char *voltea_string(char *s){
  // definimos la variable de respuesta utilizando y le alojamos espacio con malloc
  char *volteado;
  volteado = malloc(strlen(s)+1);
  if(volteado != NULL){
    int size = strlen(s);
    /* creamos variable temporal para hacer las operaciones de invertir el string
    pues las variables alojadas con malloc no permten recibir valores individuales,
    es decir, volteado[i] = s[i]*/
    char temp[size+1];
    int i=0;
    while(i<size){
      temp[i] = s[size-1-i];
      i++;
    }
  temp[i+1] = '\0';
  // Copiamos el string temporal a la variable de volteado
  strcpy(volteado, temp);
  }
  return volteado;
}
