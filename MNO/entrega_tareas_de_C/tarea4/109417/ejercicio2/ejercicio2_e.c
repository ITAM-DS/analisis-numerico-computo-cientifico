#include<stdio.h> 
#include<string.h>
#define MAXLINEA 1000 /*mximo tamaño de una lnea*/
/*definicin de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
void voltea(void);
/*imprime la lnea con tamaño ms grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    strcpy(linea,"");
    while((longitud = obtenlinea()) > 0){
	strcpy(linea_max, "");
	//printf("linea:::%s", linea);
     	voltea();
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
    int i,j;
    extern char linea[], linea_max[];
    i= 0;
    j= 1;
    while (j){
    	*(linea_max + i) = *(linea + i);
        if(*(linea_max +i)=='\0')
		j=0;
	i++;
    }
}

void voltea(void){
    int i,j;
    extern char linea[], linea_max[];
    i = 0;
    j = strlen(linea) -1 ;
    int stop = 1;
   // printf("inicio::: %d, fin:::%d\n",i,j);
   // printf("linea:::%s\n", linea);
   //printf("linea max :::: %s\n", linea_max);
    while (stop){
	linea_max[i] = linea[j];
	if(linea_max[i]=='\0')
		stop = 0 ;
	i++;
        j--;
    }
}
