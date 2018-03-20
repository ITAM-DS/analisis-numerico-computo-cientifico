/ Tarea 4

// 175952
// Peña Albarrán Karen Esther



// Ejercicio 2e
// Escribe una función `voltea` que reciba un string `s` e imprima el string `s` al revés




# include <stdio.h>
# include <string.h>

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
    voltea();
    return i;
}


/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(linea_max[i] != '\0' ){
        linea_max[i] = linea[i];
        i++;    
    }
}


/*voltea: invierte el arreglo "linea"*/
void voltea(void){
    extern char linea[];
    int l = strlen(linea), k;
    char rev[l + 1];
    for(k = 0; k < l ; k++){
        //printf("k %d \n", k);
        rev[l - k - 1] = linea[k];
      }
    rev[k]='\0' ;
    printf("%s\n", rev);
}