# Tarea 2
#### 1) Investiga lo que quieren decir las letras `EOF`. ¿Por qué se debe definir c como `int`?
Las letras `EOF` significan End Of File. La letra c se define como `int` para habilitar a la variable `EOF`. 

#### 2) Modifica `main` para que sólo se llame una vez a la función `getchar()`

`main` modificado

```c
#include <stdio.h>
main(void){
    int c;
    while( (c = getcahr()) != EOF){
        putchar(c);
    } 
}

```

#### 3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina.
