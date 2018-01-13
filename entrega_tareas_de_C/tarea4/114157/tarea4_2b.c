#include<stdio.h>
#define MAXLINEA 1000 /*m  ximo tama  o de una l  nea*/
/*definici  n de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);

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
      printf("%s", linea_max);
    return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
  int c;
  int i;
  int j = 0;
  extern char linea[];
  
  for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)

  if( c != ' ' )
    linea[j++] = c;// inciso B
  
  if(c == '\n'){
    linea[j++] = c;
    i++;
  }
  linea[i]='\0'; //este caracter es necesario para almacenar strings
  return i;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
  int i;
  extern char linea[], linea_max[];
  i=0;
  while(1){
    linea_max[i] = linea[i];
    if(linea_max[i] == '\0') break;
    i++;    
  }
}
