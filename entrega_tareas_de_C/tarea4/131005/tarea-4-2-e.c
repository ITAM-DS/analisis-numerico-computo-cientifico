#include<stdio.h>
#include<string.h>

#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void voltea(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
        if( longitud > 1){
            max = longitud;
            voltea();
        }
    if(max > 0)
        printf("%s", linea_max);
    max = 0;
    }
    printf("\n");
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

/*voltea: voltea el arreglo "linea" al arreglo "linea_max"*/
void voltea(void){
    int i, con, flag;
    extern char linea[], linea_max[];
    i=0;
    con = strlen(linea) - 1;
    flag = 1;
    while(flag){
        linea_max[i] = linea[con];
        if(linea_max[i] == '\0')
            flag = 0;
        i++;
        con--;
    }
}
