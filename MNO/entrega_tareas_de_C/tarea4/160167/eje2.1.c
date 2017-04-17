//Tarea 4 By Ricardo Lastra

//Ejercio 2

//d) Modifica la función copia para que no use índices y sólo apuntadores.

//e) Escribe una función voltea que reciba un string s e imprima el string s al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.

//f) Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

//RESPUESTA INCISO f):  Es un KeyWord que sirve para que las variables puedan ser llamadas en diferentes funciones.
//Poseen un tiempo de vida permanente, segun lo visto en clase se definen o se  declaran fuera de las funciones que en este caso en las  3 funciones comentadas se pueden obtener las variables declaradas para diferentes funciones.


#include<stdio.h>
#include<string.h> 

#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/ 
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];
 /*Prototipo de funciones:*/
int obtenlinea(void);
void copia(void);
void voltea(void);
/*imprime la línea con tamaño más 
grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0){
	if( longitud > 80){
		printf("%s\n", linea+1);
		}
	}
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(max > 0)
        printf("%s", linea_max); return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/ 
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n';i++){
	if(c != 32 ){
		linea[i] = c;
	}
    	else{
		i = i--;
	}
}
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    voltea();

    return i;
}
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/ 
void copia(void){//INCISO d)
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(i){
   	linea_max[i] = linea[i];
        if(linea_max[i] == '\0')
        i--;
	}
}

void voltea(void){//INCISO e)
    int i;
    int j;
    extern char linea[], linea_max[];
    i=0;
    j= strlen(linea) -1;
    while(j != 0){
	*(linea_max + i) = *(linea + j);
	i++, 
	j--;
    }
}
