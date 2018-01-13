# Tarea 2

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

1) Investiga lo que quieren decir las letras `EOF`. ¿Por qué se debe definir c como `int`?

2) Modifica `main` para que sólo se llame una vez a la función `getchar()`

3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:

```
$echo -e "hola\n" | ./ejecutable.out
```

entonces el programa imprime `4`

4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de `stdin`:

```
./ejecutable.out < archivo.txt
```

De manera individual cada persona haga un directorio con su clave y coloquen ahí sus resultados.

Se entrega el lunes 13 de febrero.
