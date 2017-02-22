Tarea 2
=======

Considera el siguiente programa:

```C
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

Si lo ejecutas, para salir del programa utiliza ctrl + c

1) Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int?

-	Las letras EOF significan **End Of File** y se debe definir como entero ya que el valor de EOF es -1. Esto es por que debe ser diferente a cualquier posible valor que getchar pueda regresar. La función getchar regresa cualquier valor de caracter como un "unsigned" char, convertido a entero, lo cual significa que jamás será negativo.

2) Modifica main para que sólo se llame una vez a la función getchar()

-	Para llamar únicamente 1 vez a la función getchar() basta con inicializar el valor de c dentro del while. Para ello primero le pedimos que ejectue la función getchar() y después evalúe el criterio del while.

```C++
#include <stdio.h>
main(void){
    int c;
    while( (c=getchar()) != EOF){
        putchar(c);  
    }
}
```

-	Compilamos la función:

```shell
$gcc Ej2_2.c -o Ej2_2.out
```

3) Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:

```shell
$echo -e "hola\n" | ./ejecutable.out
```

Entonces el programa imprime 4.

-	El código que genera el número de caracteres dado un stdin es:

```C
#include <stdio.h>
main(void){
   //inicializamos la variable que tomara el valor de cada caracter del arreglo;
   int c;

   // inicializamos el contador de caracteres;
   long num_char;
   num_char = 0;

   // recorremos el string hasta que veamos el interlineado y vamos contando el numero de caracteres;
   while ((c=getchar()) != EOF && c!='\n'){
       ++num_char;
   }

   //imprimimos el resultado;
   printf("%ld\n", num_char);
}
```

-	Compilamos la función:

```shell
$gcc Ej2_3.c -o Ej2_3.out
```

```shell
$echo -e "hola\n" | ./Ej2_3.out
4
```

4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin:

```shell
$ ./ejecutable.out < archivo.txt
```

-	El programa que cuenta el número de líneas dad un archivo de stdin es:

```C
#include <stdio.h>
main(void){
    //inicializamos la variable que tomara el valor de cada caracter del arreglo;
    int c;

    // inicializamos el contador de renglones;
    long row_count;
    row_count=0;

   // recorremos el string hasta que veamos el interlineado y aumentamos el contador de renglones;
    while ((c = fgetc(stdin)) != EOF){
        if(c == '\n'){
            ++row_count;
        }
    }

    //imprimimos el resultado;
    printf("%ld\n",row_count);
}
```

-	Compilamos la función:

```shell
$gcc Ej2_4.c -o Ej2_4.out
```

-	El cual lo podemos ejectuar tal y como se muestra en el ejemplo. Para ello hemos generado un archivo .txt que contiene 100 regnlones de la siguiente manera:

```shell
$seq 100 > archivo2.txt
```

-	Y ejecutamos nuestra fucnión dando los siguientes resultados:

```shell
$./Ej2_4.out < archivo2.txt
100
```
