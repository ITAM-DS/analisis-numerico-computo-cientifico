#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
#define MAXLINEAS 80
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);

/*imprime la línea con tamaño más grande*/
extern int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud >= MAXLINEAS){
            copia();
            printf("%s", linea_max);
        }
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
extern int obtenlinea(void){
    int c;
    int i;
    int j=0 ;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    if( c != ' ')
	linea[j++] = c; //Para quitar los espacios
    linea[j]='\0'; //este caracter es necesario para almacenar strings
    return i;
    return j;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
extern void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        *(linea_max+i) = *(linea+i);
        if(linea_max[i] == '\0'){
        i++;
	}
	*(linea_max+i) = *(linea+i);
    }

void voltea(void){ 
    int i, k;
    char str[100], temp;
    i=0;
    k=strlen(str);
    while(i<k){
        temp = *(str+i);
	*(str+i) = *(str+k);
	*(str+k) = temp;
	i++;
	k--;
        }
    printf("\n string al revés :%s", str);
    }
}


