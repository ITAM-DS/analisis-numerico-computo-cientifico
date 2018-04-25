#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
char linea_volteada[MAXLINEA];

/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
void voltea(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern char linea_volteada[MAXLINEA];
    while((longitud = obtenlinea()) > 0){
            voltea();
	    printf("%s", linea_volteada);
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

void voltea(void){ 
    int i;
    extern char linea[], linea_volteada[];
    
    char *from = linea;
    char *to = linea_volteada;
    
    // Se empieza el apuntador from desde el ultimo caracter
    from = from + strlen(linea) - 1;
    
    // Mientras el apuntador no sea igual a la primera posicion de linea, copia
    while( from != linea){
        *to = *from;
        to = to + 1;
        // El apuntador from va en reversa
        from = from - 1;
    }
    // El primer caracter se copia manualmente (el loop no lo hace)
    *to = *from;
    *(to+1) = '\0';
}
