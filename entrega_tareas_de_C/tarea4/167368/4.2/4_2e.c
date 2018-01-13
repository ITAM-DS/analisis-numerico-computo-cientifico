//4.2e) Escribe una función voltea que reciba un string s e imprima el string s al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.

// 4.2f) ¿Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

// Sirve para que busque la variable fuera de la función...si no la encuentra...



#include<stdio.h>
#include<string.h>

#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
//char linea_revez[MAXLINEA]; 

/*Prototipo de funciones:*/
 
int obtenlinea(void); 
void copia(void);
void voltea(char s);
 
/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];

    while((longitud = obtenlinea()) > 0)
        if(longitud > 80)
            voltea(*linea);
        // la función "voltea" hace toda la chamba (copy+print)
    
return 0;
}
 
//*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
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
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(*(linea) != '\0'){  // (2d)
        *(linea_max+i) = *(linea+i); // (2d)
        i++;
    }
}

void voltea(char s){
    extern char linea[];
    int len = strlen(linea);
    int i;
    char aenil[len + 1];
    for(i = 0; i < len ; i++){
        aenil[len - i - 1] = linea[i];
    }
    aenil[i]='\0';
    printf("%s\n", aenil);
}