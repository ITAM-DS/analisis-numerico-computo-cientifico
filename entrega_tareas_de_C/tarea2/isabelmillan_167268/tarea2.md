1.- Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int?

EOF significa End Of File, por default tiene un valor entero igual a -1, es una macro que determina el final de un archivo.
En el programa, c= getchar(). Es necesario definirlo como entero para poder habilitar a EOF.    

2.- Modifica main para que solo se llame una vez a la función getchar()

```
#include <stdio.h>
int main(void){
    int c;
    while( (c = getchar()) != EOF){
        putchar(c);   
    } 
}
```

3.- Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número. Al dar enter (salto de línea) el programa termina.

```
#include <stdio.h>
int main(void){
    int c;
    int n =0;

         while( (c = getchar()) != '\n'){
                n++;
        }
    printf("El número de caracteres es %d\n", n);
}
```

4.- Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin

```
#include <stdio.h>
int main(void){
    int c;
    int linea =0;
    while( (c = getchar()) != EOF){
	if(c=='\n')
	linea++;
    }
    printf("Número de líneas en el archivo  %d\n",linea);
} 
```
