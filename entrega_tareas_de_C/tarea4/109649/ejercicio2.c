#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
char linea[MAXLINEA];
char linea_copia[MAXLINEA];
char linea_junta[MAXLINEA];
 
/*Prototipo de funciones:*/
 
int obtenlinea(void);
void copia(int);
void quita_espacios(void);
void copia_apuntadores(char*, char*, int);
void voltea(char*, int);
 
/*imprime la línea con tamaño mayor a 80 caracteres*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_copia[MAXLINEA];
    printf("\n\na) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.\n\n");
    while((longitud = obtenlinea()) > 0)
        if( longitud > 80){
            copia(longitud);
            printf("%s\n", linea);
        }

     rewind(stdin);
     printf("\n\n\nb) Modifica el programa para que quite los espacios de cada línea leída.\n\n");
     while((longitud = obtenlinea()) > 0){
        quita_espacios();
        printf("%s", linea_junta);
     }
    printf("\n\nc) Modifica la funci  n copia para que no use break pero todavía debe de usar el índice i.");
    printf("\n los outputs correspondientes están hechos utlilizando esta modificación\n");

    printf("\n\n d) Modifica la función `copia` para que no use índices y sólo apuntadores.");
    printf("\n Se ejecuta el código copia_apuntadores");
    rewind(stdin);
    
    char *apuntador_linea;
    char *apuntador_linea_copia;
    int n=0;

    while((longitud = obtenlinea()) > 0){
            apuntador_linea = linea;
            apuntador_linea_copia = linea_copia;
            copia_apuntadores(apuntador_linea, apuntador_linea_copia, longitud);
            n++;
            printf("copia_apuntadores, copiada línea %d \n", n);
    }

    printf("\n\n e) Escribe una función `voltea` que reciba un string `s` e imprima el string `s` al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.\n\n");
    rewind(stdin);

    while((longitud = obtenlinea()) > 0){
        longitud = obtenlinea();
        apuntador_linea = linea;
        voltea(apuntador_linea, longitud);
}

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
 
/*copia: copia del arreglo "linea" al arreglo "linea_max" sin el uso de break*/
void copia(int longitud){
    int i;
    extern char linea[], linea_copia[];
    for (i=0;i<=longitud;i++){
        linea_copia[i] = linea[i];
    }
}

/* copia_apuntadores es la modificación de copia para su uso solo con apuntadores */
void copia_apuntadores(char *apuntador_linea, char *apuntador_linea_copia, int longitud){
    int i = 0;
    for (i=0;i<=longitud;i++){
        *apuntador_linea_copia = *apuntador_linea;
        apuntador_linea++;
        apuntador_linea_copia++;
    }
}

//Función para quitar espacios en cada línea
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

//Función voltea que refleja el string s que se le manda
void voltea(char *apuntador_linea, int longitud){
    char linea_volteada[longitud];
    int i = 0;
    for(i=0;i<longitud;i++){
        printf("%c", *(apuntador_linea+longitud-i-1));
    }
}