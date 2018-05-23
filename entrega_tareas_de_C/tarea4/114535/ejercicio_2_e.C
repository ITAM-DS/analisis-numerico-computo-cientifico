#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
int longitud; 
/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void voltea(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    extern int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    while((longitud = obtenlinea()) > 0)
    	voltea();
	printf("%s", linea_max);
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
 
// Función para voltear linea en el arreglo. Imprime el arreglo volteado
void voltea(void){
	int i, n, u;
	extern char linea[], linea_max[];
	extern int longitud;
	i=0;
	n=longitud+10;
	// printf("%s", linea);
    	linea_max[n+1]='\0';
	while(1){
		linea_max[n-i] = linea[i];
		if(linea[i]=='\0'){
		//printf(" %s \n", linea);
		for(u=0;u<n;u++){
			printf("%c",linea_max[u]);
		}
		break;
		}
		i++;	
	}
}
