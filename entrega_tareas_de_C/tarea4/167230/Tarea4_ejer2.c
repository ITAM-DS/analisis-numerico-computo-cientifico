/*
PUNTO A) linea: 34
PUNTO B) linea: 61
PUNTO C) linea: 85
PUNTO D) linea: 85
PUNTO E) linea: 39 y 91
PUNTO F) Escribir la palabra extern en las declaraciones de main, getline y copia le indican al compilador
que la variable mencionada se encuentra fuera del dominio de la función, ya sea al inicio de este archivo o
en un archivo complementario. En nuestro caso podemos no incluir extern, ya que el compilador ubicó la declaración
de las variables globales dentro de este archivo.
*/

#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
void voltea(char* s);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
        
        // ### PUNTO A)
        if (longitud > 80)
        {
            printf("%s\n", linea);
        
        // ### PUNTO E)
            voltea(linea);
        }

        if( longitud > max){
            max = longitud;
            copia();
        }
    }
    if(max > 0){
        printf("%s", linea_max);
        voltea(linea_max);
    }
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){
        // ### PUNTO B)
        if (c==' ')
        {
            i--;
        }
        else{
            linea[i] = c;    
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
    // ### PUNTO C) y D)
    while((*(linea_max+i) = *(linea+i)) != '\0'){
        i++;
    }
}

// ### PUNTO E)
void voltea(char *s){
    int i, tam;
    for (i = 0; (*(s+i))!='\0'; ++i)
    {   
    }
    tam = i;
    //printf("%d\n", tam);
    for (i = tam; i >= 0 ; --i)
    {
    printf("%c", *(s+i));
    }
}