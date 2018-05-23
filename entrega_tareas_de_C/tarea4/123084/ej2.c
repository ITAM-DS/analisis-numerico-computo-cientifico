#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

//inciso 2d) Las palabras exxtern permiten a las funciones llamar y alterar variables de ambiente global,
// por encima del ambiente local de la función.
 
/* Prototipo de funciones: */
 
int obtenlinea(void); 
void copia(void);
void voltea(char*);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            if( longitud > 80){ //inciso 2a)
                max = longitud;
                copia();
            }
        }
    if(max > 0){
        
        voltea(linea_max);
    }
return 0;
}
 
/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i,j;
    extern char linea[];

    for(i=0,j=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){
        if( c != ' '){  //inciso 2b)
        linea[j] = c;
        j++;
        }
    }
    if(c == '\n'){
        linea[j] = c;
        i++;
        j++;
    }
    linea[j]='\0'; //este caracter es necesario para almacenar strings


    return i;
}
 
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    // inicializa i
    int i;
    // obten ambos arreglos, linea y linea max.
    extern char linea[], linea_max[];
    i=0;
    while(linea[i] != '\0'){ //inciso 2c)
        *(linea_max+i) = *(linea+i); //inciso 2d)
        i++;    
    }

}


void voltea(char *line){ //inciso 2e)
    

    int count =0,i;
    

    while(line[count] !='\0'){
        count++;
    }
    
    int end = count-1;

    for( i =0; i<count; i++){
        
        printf("%c", line[end]);
        end--;
    }

    printf("\n");

}