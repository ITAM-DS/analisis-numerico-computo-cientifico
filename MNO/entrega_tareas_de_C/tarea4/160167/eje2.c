//Tarea 4 By Ricardo Lastra

//Ejercicio 2

//a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.

//b) Modifica el programa para que quite los espacios de cada línea leída.

//c) Modifica la función copia para que no use break pero todavía debe de usar el índice i.

//Se modifica programa segun instrucciones a), b), c)


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
	if( longitud > 80){//INCISO a)
		printf("%s\n", linea+1);
		}
	}
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
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){//INCISO b)
	if(c != 32 ){ //espacio en codigo ASCII
		linea[i] = c;
	}
    	else{
		i = i--;
	}
}
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
    while(1){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0')
        i--;//INCISO c)
    }
}
