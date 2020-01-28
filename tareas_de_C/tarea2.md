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

Si lo ejecutas para salir del programa utiliza `ctrl + c`.

1) Investiga lo que quieren decir las letras `EOF`. ¿Por qué se debe definir c como `int`?

2) Modifica `main` para eliminar la línea:

```
    c = getchar();
```

antes del while y hacer el llamado a getchar en la condición del while.


3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:

```
$echo -e "hola\n" | ./ejecutable.out
```

entonces el programa imprime `4`

4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de `stdin`:

```
./ejecutable.out < archivo.txt
```

