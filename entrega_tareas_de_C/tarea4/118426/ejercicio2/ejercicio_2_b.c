#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
char linea[MAXLINEA];
char linea_print[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void);
void copia(void);

/* Imprime todas las líneas con longitud mayor a 0*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    while((longitud = obtenlinea()) > 0){
        copia();
        printf("%s", linea_print);
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
    linea[i]='\0';
    return i;
}

/*copia: copia del arreglo "linea" al arreglo "linea_print"*/

void copia(void){
    int i,j;
    extern char linea[], linea_print[];
    i=0;   // va a buscar espacios dentro de la linea
    j=0;   // va recorriendo sobre el arreglo donde está copiando
    while(1){
	if(linea[i] == ' '){ //encuentra los espacios y se salta al siguiente caracter
	    i++;
	}
	else{
            linea_print[j] = linea[i];  //copia el caracter cuado no es espacio
            if(linea_print[j] == '\0') break;
            i++;
	    j++;
	}
    }
}




