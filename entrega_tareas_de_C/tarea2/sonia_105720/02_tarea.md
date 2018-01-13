


# Tarea 2

---

**CU:** 105720

**Nombre:** Sonia Mendizábal Claustro

---



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

> 1) Investiga lo que quieren decir las letras `EOF`. ¿Por qué se debe definir c como `int`?

`EOF` significa `End Of File`. Generalmente es entero -1
Es una macro que define un entero negativo producto 
de varias funciones para determinar el final de un archivo. 
Similar a ctrl + D. Se debe definir c como integer para habilitar EOF. 

> 2) Modifica `main` para que sólo se llame una vez a la función `getchar()`

```
#include <stdio.h>
main(void){
    int c;
    while( (c = getchar()) != EOF){
        putchar(c);
    } 
}
```

> 3) Utiliza `getchar` para escribir un programa que cuente el número de caracteres dado un `stdin` e imprima este número. Al dar enter (salto de línea) el programa termina.

En la carpeta se ecnuentra el archivo en c `02a_tarea_countchar.c`
con la función para contar el número de caracteres. 
De tal forma que una vez ejecutado el 
archivo, el comando queda de la siguiente forma. 

```
$echo -e "hola\n" | ./02a_tarea_countchar.out
```

La función para obtener el número de caracteres
es la siguiente.

```
#include <stdio.h>
#include <string.h>

int main(void){
    char str[100];
    int c, n = 0, len;
    
    while( (c = getchar()) != '\n'){
        str[n] = c;
        n++;
        
    } 
    len = strlen(str);
    printf("%d\n", len);
    printf("\n");

return(0);
}
```




> 4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de `stdin`.

En la carpeta se ecnuentra el archivo en c `02b_tarea_countline.c`
contiene la función para contar el número de líneas. 
De tal forma que el comando queda de la siguiente forma. 

```
./02b_tarea_countline.out < archivo.txt
```

La función modificada del archivo `02b_tarea_countline.c` es 
la siguiente. 


```
#include <stdio.h>

int main(void){
    char aux;
    int c, n = 0, lineas = 0;

    while( (c = getchar()) != EOF){
        aux = c;
        
        if(aux == '\n'){
            lineas++;
        }
        n++;
    } 

    printf("count lineas %d\n", lineas);
    printf("\n");

return(0);
}
```