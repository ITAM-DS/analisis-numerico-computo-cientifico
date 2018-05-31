#include<stdio.h>
#define MAXLINEA 100000 /*máximo tamaño de una línea*/
 
/*definición de variables externas*/
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    while((longitud = obtenlinea()) > 0)
            printf("\n");
return 0;
}
  
 
/*Modificado para leer texto y no imprimir espacios*/
// Cumple con requisito b) Modifica el programa para que quite los espacios de cada línea leída.
int obtenlinea(void){
    int c;
    int i;
    int less=0;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF; i++)
	if(c==' '){
		if(i!=0){
			less++;
		}else{
		linea[i] = c;
		}
	} else{
		linea[i-less] = c;
		printf("%c", linea[i-less]);
		if(c == '\n'){
			linea[i-less] = c;
			i++;
		}
		linea[i-less]='\0'; //este caracter es necesario para almacenar strings
	}
    return i;
}
 
