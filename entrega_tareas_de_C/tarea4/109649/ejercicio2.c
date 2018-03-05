#include<stdio.h>
#define MAXLINEA 1000 /*m  ximo tama  o de una l  nea*/
/*definici  n de variables externas*/
char linea[MAXLINEA];
char linea_max[MAXLINEA];
char linea_junta[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void);
void copia(int);
void quita_espacios(void);
 
/*imprime la l  nea con tama  o m  s grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    printf("\n\na) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.\n\n");
    while((longitud = obtenlinea()) > 0)
        if( longitud > 80){
            copia();
            printf("%s\n", linea);
        }

     rewind(stdin);
     printf("\n\n\nb) Modifica el programa para que quite los espacios de cada línea leída.\n\n");
     while((longitud = obtenlinea()) > 0){
        quita_espacios();
        printf("%s", linea_junta);
     }
    printf("\n\nc) Modifica la funci  n copia para que no use break pero todavía debe de usar el índice i.");
    printt("\n los outputs correspondientes están hechos utlilizando esta modificación")
    return 0;
}
 
/*obtenlinea: lee una línea en el arreglo linea, regresa longitud*/
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
void copia(int longitud){
    int i;
    extern char linea[], linea_max[];
    for (i=0;i<=longitud;i++){
        linea_max[i] = linea[i];
    }
}

//Funci  n para quitar espacios en cada l  nea
void quita_espacios(void){
    int i=0;
    int j=0;
    extern char linea[];
    extern char linea_junta[];
        while(1){
            if(linea[i] == '\0') break;
            if(linea[i] == ' '){
                 i++;
                }
            else {
                linea_junta[j] = linea[i];
                i++;
                j++;
                }
        }
}
