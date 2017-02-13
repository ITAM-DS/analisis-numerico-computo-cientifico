#Tarea 2

####Javier Quiroz (18949)

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


***Solución***:

EOF es acrónimo de End of File (fin de archivo). Cada archivo en la arquitectura de sistemas Unix esta terminado con un caracter que asi se nombra. En el header stdio.h esta definido como -1. La función getchar devuelve -1 cuando ha encontrado el fin de archivo (cosa que sucede cuando se usa redirección de Stdin y el archivo a alcanzado su fin), Cuando Stdin esta conectada al tecldo este se alcanza cuando escribimos Ctrl-z.

Es común que en Unix los caracteres ASCII se usen como enteros para poder hacer aritmética con ellos. Asi al sumarle a 'A' el número 2 se obtiene 'C', etc. Por ello en el prototipo de la funcion se usa int.

2) Modifica `main` para que sólo se llame una vez a la función `getchar()`

***Solución***:
```
#include <stdio.h>
main(void){
    int c;
    
    while( (c = getchar() ) != EOF){
        putchar(c);
    } 
}
```

3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:

```
$echo -e "hola\n" | ./ejecutable.out
```

***Solución***:
```
#include <stdio.h>

int main(void){
    int c;
    int n = 0;

    while( (c = getchar() ) != '\n'){
        n++;
        putchar(c);

    }
    printf("\n\n Numero de caracteres %d", n );

    return EXIT_SUCCESS;
}
```


entonces el programa imprime `4`

4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de `stdin`:

```
./ejecutable.out < archivo.txt
```
***Solución***:
```
#include <stdio.h>

int main(void){
    int c;
    int n = 0;

    while( (c = getchar() ) != EOF){

        putchar(c);
        if (c == '\n')
        	n++;
    }
    printf("\n\n Numero de lineas %d", n );

    return EXIT_SUCCESS;
}
```

De manera individual cada persona haga un directorio con su clave y coloquen ahí sus resultados.

Se entrega el lunes 13 de febrero.
