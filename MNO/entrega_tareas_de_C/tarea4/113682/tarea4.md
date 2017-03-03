# Tarea 4

--------

## Ejercicio 1

a) Modifica la función longitud_string:

```
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
int i;
i=0;
while(*s != '\0'){
    s = s + 1;
    i++;
}
return i;
}

```

b)  Investiga el uso de la función scanf para que imprima la longitud de los strings del archivo.txt:


```
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
int longitud_string(char *s){
int i;
i=0;
while(*s != '\0'){
s = s + 1;
i++;
}
return i;
}

int main(void){
char str[MAX_LONG];
while(scanf("%s", str) != EOF){
printf("longitud %s: %d\n", str, longitud_string(str));
}
return 0;

```

-------

## Ejercicio 2

a) Modifica el programa para que imprima sólo aquellas líneas que tienen más de 80 caracteres.

Parte modificada

```
/*imprime la línea con tamaño mayor a 80 caracteres*/

int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=80;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            copia();
            printf("%s", linea_max);
        }

return 0;
}

```

b) Modifica el programa para que quite los espacios de cada línea leída.

Parte modificada

```
/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++){

        if( c != ' ')
            linea[i] = c;
        else
            i=i-1;
    }
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}
```

c) Modifica la función copia para que no use break pero todavía debe de usar el índice i.

Parte modificada

```
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(linea_max[i] != '\0'){
        linea_max[i] = linea[i];
        i++;    
    }
}
```

d) Modifica la función copia para que no use índices y sólo apuntadores.

Parte modificada

```
/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    extern char linea[], linea_max[];
    linea_max = linea
}
```
e) Escribe una función voltea que reciba un string s e imprima el string s al revés. Añade esta función para que el programa lea líneas y las imprima volteadas.

```
void voltea(int m){
extern char linea[], linea_max[];
int i;
for(i=m; i > -1; i--)
linea_max[i] = linea[(size-1)-i];
}
```
f) Qué efecto tiene escribir extern para la declaración de variables dentro de main(), getline() y copia()?

Llama a las variables de otras funciones. 

## Ejercicio 3






