#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
#define MAX_LONG 200
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
void del_space(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
		copia();
		del_space();
		printf("%s", linea_max);
        }
   // if(max > 0)
     //   printf("%s", linea_max);
	
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
    extern char linea[], linea_max[];
    i=0;
    while(linea_max[i] == '\0'){
        linea_max[i] = linea[i];
        i++;    
    }
}

void del_space(void) {
  char *pointer_line = linea;
  char *line_wos = linea_max;
  while (*pointer_line != '\0'){
	if (*pointer_line != ' '){
	*line_wos = *pointer_line;
	line_wos++;
	}
	pointer_line++;
    }
    *line_wos = '\0';	
}

