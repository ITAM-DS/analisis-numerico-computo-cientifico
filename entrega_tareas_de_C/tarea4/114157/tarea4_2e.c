#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*m  ximo tama  o de una l  nea*/
/*definici  n de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
void voltea(void);

/*imprime la l  nea con tama  o m  s grande*/
int main(void){
  int longitud;
  extern int max;
  extern char linea_max[MAXLINEA];
  max=0;
  while((longitud = obtenlinea()) > 0)
    if( longitud > max){
      max = longitud;
      copia();
    }
    if(max > 0)
      printf("\n%s", linea_max);
    return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
  int c;
  int i;
  extern char linea[];
  for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
    linea[i] = c;
  if(c == '\n'){
    linea[i] = c;
    i++;
  }
  linea[i]='\0'; //este caracter es necesario para almacenar strings
  voltea();
  return i;
}


/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
  int i;
  extern char linea[], linea_max[];
  i=0;
  while( (*(linea_max + i) = *(linea + i)) != '\0'){ //inciso C y D
    i++;    
  }
}

/*voltea: imprime el string al rev  s*/
void voltea(void){
  extern char linea[], linea_max[];
  int tam = strlen(linea);
  int i;
  
  for (i = tam; i >= 0 ; --i){
    printf("%c", *(linea + i));
  }
} 