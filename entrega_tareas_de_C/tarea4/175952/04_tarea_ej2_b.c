 // Tarea 4

// 175952
// Karen Esther Peña Albarrán



// Ejercicio 2b
// Modifica el programa para que quite los espacios de cada línea leída.




# include <stdio.h>
# include <string.h>
# include <ctype.h> // para función isspace(c)

# define MAXLINEA 1000 /*máximo tamaño de una línea*/

/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 
 
/*Prototipo de funciones:*/
int obtenlinea(void); 
void copia(void);
void voltea(void);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }        
    if(max > 0)
        printf("Línea con máxima longitud: %s\n", linea_max);
        
return 0;
}
 
 
/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c, i, k = 0; // k nuevo indice para dimensión sin espacios
    extern char linea[];
    
    for(i=0; i < MAXLINEA-1 && (c = getchar()) != EOF && c!= '\n'; i++)
        // b) Omite blankspace
        if( !isspace(c) )
            linea[k++] = c;
        if(c == '\n'){
            linea[k++] = c;
            i++;
        }
    linea[k]='\0'; //este caracter es necesario para almacenar strings
    
    return i;
}

 
 
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(1){
        linea_max[i] = linea[i];
        if(linea_max[i] == '\0') break;
        i++;    
    }
}