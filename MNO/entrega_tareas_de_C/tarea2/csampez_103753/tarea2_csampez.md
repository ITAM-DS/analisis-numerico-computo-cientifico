# Tarea 2

## Carlos S. Pérez Pérez 103753
 
Sea ```char_input.c``` el siguiente código

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

### R1

EOF es la abreviatura de end-of-file, fin de archivo en inglés es un indicador o marca de que no hay más información que recuperar de una fuente de datos, cualquiera que esta sea: un archivo o un flujo de datos.

La variable **c** se debe declarar como *int* ya que la función ```getchar``` regresa los valores de caracteres como *unsigned char* convertido a *int*, de modo que siempre es un número no negativo. En otras palabras ```getchar``` reporta los valores de los bytes usando números del 0 al 255 y el valor de EOF es -1, el cual es un valor que se obtiene cuando ```getchar``` ya no recibe nada. 


### R2 

Modificación de `main` para que sólo se llame una vez a la función ```getchar```. Archivo **getchar_once.out**


```
#include <stdio.h>
int main(void){
    int c;
    while( (c = getchar()) != EOF){
        putchar(c);   
    } 
}
```


### R3 

El programa es como sigue (archivo **count_char.out**)
```
#include <stdio.h>
int main(void){
    int c;
    long nc = 0;
    while( (c=getchar()) != '\n'){
        ++nc;   
    } 
    printf("El total de caracteres es %ld\n", nc);
}
```

Se ejecuta con éxito ```echo -e "hola\n" | ./count_char.out```

### R4 

Modificación para que cuente el número de líneas dado un archivo el cual se debe ejecutar 
```./count_lines.out < archivo.txt```

```
##include <stdio.h>
int main(void){
    long nl = 0;
    int c;
    while( (c=getchar()) != EOF ) {
        if ( c == ('\n') ) {
            ++nl;
        }
    }
    printf("El total de lineas es %ld\n", nl);
}
```

