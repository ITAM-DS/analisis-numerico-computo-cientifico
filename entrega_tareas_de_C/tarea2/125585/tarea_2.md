#Tarea 2

Considera el siguiente programa:

```
#include <stdio.h>
main(void){
    int c;
    c = getchar();
    while( c != EOF){
        putchar(c);
        c = getchar();   
    } 
}
```

Si lo ejecutas, para salir del programa utiliza `ctrl + c`

## 1) Investiga lo que quieren decir las letras `EOF`. ¿Por qué se debe definir c como `int`?  

`EOF` quiere decir End Of File. En C el `EOF` es representado por un -1, por eso es que la varible `c` debe ser declarada como int.  
Sin embargo no se debe probar contra el valor -1 sino contra `EOF` porque no todos los sistemas arrojan el mismo resultado. EOF se asegura de homologar las cosas a -1. 

##2) Modifica `main` para que sólo se llame una vez a la función `getchar()`

```
#include <stdio.h>
main(void){
    int c;
    while( (c= getchar()) != EOF){
        putchar(c);  
    } 
}
```

##3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:


```
#include <stdio.h>
void main(){
    int c,count_char=0;
    
    while( (c= getchar()) != '\n'){
        count_char= count_char +1;  
    } 
    printf("Número de caracteres antes del salto de  linea: %d \n", count_char);
}
```
```
$echo -e "hola\n" | ./ejecutable.out
```

entonces el programa imprime `4`

##4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de `stdin`:

```
#include <stdio.h>
void main(){
    int c,count_lines=0;
    
    while( (c= getchar()) != EOF){
    	if(c == '\n') 
        count_lines = count_lines +1;  
    } 
    printf("Número de lineas en el documento son : %d \n", count_lines);
}
```
```
./ejecutable.out < archivo.txt
```

De manera individual cada persona haga un directorio con su clave y coloquen ahí sus resultados.

Se entrega el lunes 13 de febrero.
