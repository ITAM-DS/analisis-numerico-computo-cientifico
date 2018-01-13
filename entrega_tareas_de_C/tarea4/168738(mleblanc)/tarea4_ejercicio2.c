#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
//extern char intermediate[];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
char *voltea(char *str);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > 80){
            copia();
            printf("NO VOLTEA--------------------\n");
            printf("\n");
            printf("%s",linea_max);
            printf("\n");
            printf("VOLTEA-----------------------\n");
            printf("\n");
            voltea(linea_max);
            printf("\n");
            //free(intermediate);


        }    
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i,j=0;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){
        if (c==' ') {

            c=getchar();
            if (c==EOF || c=='\n'){break;}
            j++;
        }

        linea[i] = c;
    }
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i+j;
}

/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;

    while(*(linea+i)!='\0'){

        *(linea_max+i)=*(linea+i);
        i++;    
    }
    linea_max[i]='\0';
    
}

//Escribe una función voltea que reciba un string s e imprima el string s al revés.
//Añade esta función para que el programa lea líneas y las imprima volteadas.

char *voltea(char *str) {
long int i;
char intermediate[strlen(str)];

    for (i=strlen(str);0<=i;i--){
        *(intermediate+(strlen(str)-i))=*(str+(i-1));

    }

intermediate[strlen(str)]='\0';
printf("%s\n",intermediate);

}

//RESPUESTA:f)Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?
//Cuando escribimos con un variable extern podemos cambiar su valor dentro esos funciones tal que este valor se conserva para todas las 
//partes del codigo y no es necessario de hacer un return para ver este valor.Por ejemplo la funcion getline()  "return" unicamente 
//el numero de caracter pero da tambien la linea porque utiliza la variable externa linea. La funcion copia es definido al inicio con void 
//porque es la misma idea no es necessario de hacer un "return" porque utiliza las variables linea y linea_max y cambia la valor de linea_max
// para todos los partes del codigo cuyo main().