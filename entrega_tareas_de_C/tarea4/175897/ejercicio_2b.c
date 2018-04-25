#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
      
    	copia();
	printf("%s", linea_max);

    }

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
    return i;
}
 
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    int j;
    extern char linea[], linea_max[];
    i=0;
    j=0; //Es necesario tener otro indice para que no nos coloque caracteres raros en caso de no copiar un caracter

    while (1)
    {
      if(linea[i]!=' ') //Revisamos si el caracter es diferente de espacio, y su lo es procedemos a guardar en el arreglo
      {
        linea_max[j] = linea[i];
	if(linea_max[j] == '\0') break;
        i++;
	j++;
      }
      else{// En caso de ser espacio nos vamos al siguiente caracter
      i++;
      }
    }
    


}

