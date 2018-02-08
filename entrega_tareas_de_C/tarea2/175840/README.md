## Tarea 2
### Miguel Rodrigo Castañeda Santiago
### CU 175840

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

EOF Corresponde a fin de archivo "End of file", se debe definir c como entero ya que
debe ser de un tipo suficientemente grande para almacenar el valor que la función getchar regrese,
no se utiliza char ya que la función getchar regresa el valor capturado más el valor EOF por lo que el tipo debe
ser int.


2) Modifica `main` para eliminar la línea:

```
    c = getchar();
```

antes del while y hacer el llamado a getchar en la condición del while.


```
#include <stdio.h>

main(void){

    int c;

    while( getchar() != EOF){
        putchar(c);
        c = getchar();
    }
}
```
Archivo: [Tarea2.c](Tarea2.c)

3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:

```
$echo -e "hola\n" | ./ejecutable.out
```

entonces el programa imprime `4`


```
#include <stdio.h>

int main(){
    int c = 0;
    while(getchar() != '\n')
        c++;

    printf("\nEl total de letras es : %d\n",c);
    return 0;
}

```
Archivo: [Tarea2_3.c](Tarea2_3.c)

Ejecutando 

```
echo -e "hola\n" | ./tarea2_3.out

El total de letras es : 4
```


4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de `stdin`:

```
./ejecutable.out < archivo.txt
```

```
#include <stdio.h>

int main(){
    int c = 0;
    int lineas = 0;
    c = getchar();
    while(c != EOF ){
        c = getchar();
        if(c == '\n')
            lineas++;
    }

    printf("\nEl total de lineas es : %d\n",lineas);
    return 0;
}
```
Archivo: [Tarea2_4.c](Tarea2_4.c)

Ejecutando 

```
./tarea2_4.out < prueba.txt

El total de lineas es : 6
```