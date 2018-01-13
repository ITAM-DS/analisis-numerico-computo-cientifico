#include<stdio.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
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
    while((longitud = obtenlinea()) > 0){
        voltea();
        printf("%s", linea_max);
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

void voltea(){
    extern char linea[], linea_max[];
    char *pointer = linea;
    char *target = linea_max;

    //printf("apuntador %p \n", linea_max);

    int i = 0;

    while(*pointer != '\0'){
        target++;
        pointer++; 
        i++;
    }
    pointer = linea;
    //target++;
    *target = '\0';
    target--;
    //*target = '\n';
    //target--;
    //printf("%d",i);
    while(*pointer != '\0'){

        *target = *pointer;
        //printf("%c ", *target);
        //printf("%p \n", target);
        target--;
        pointer++; 

    }


    //printf("%s", linea_max);
    //printf("linea max %p\n", linea_max);
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    extern char linea[], linea_max[];
    char *pointer = linea;
    char *target = linea_max;
    while(*pointer != '\0'){
        *target = *pointer;
        pointer += 1;
        target += 1; 

    }
}