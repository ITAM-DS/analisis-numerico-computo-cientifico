#Tarea 2

Considera el siguiente programa:

```
#include <stdio.h>
int main(void){
    int c;
    c = getchar();
    while( c != EOF){
        putchar(c);
        c = getchar();   
    } 
}
```

Si lo ejecutas, para salir del programa utiliza `ctrl + c`

- Investiga lo que quieren decir las letras `EOF`. 
Do
- EOF (End of File)
Cuando en el flujo de un archivo de entrada ya no hay mas datos por leer entonces la función EOF regresa distinto a cero y cero si los hay.

- ¿Por qué se debe definir c como `int`?
Porque la función getchar regresa un entero a pesar de que se utiliza para hallar el caracter que se halle en el standard input.

12
2) Modifica `main` para que sólo se llame una vez a la función `getchar()`

```
#include <stdio.h>
int main(void){
    int c = getchar();
    while( (c = getchar()) != EOF){
        putchar(c);   
    } 
}

```

3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:

```
$echo -e "hola\n" | ./ejecutable.out
```

entonces el programa imprime `4`

4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de `stdin`:

```
./ejecutable.out < archivo.txt
```


