# Tarea 2
## Raúl Zagal Rojo - 167230

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

## 1) Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int?

Las siglas EOF significan "End Of File", o final de archivo, el cual es un caracter especial que indica al programa que ya no se enviaran más comandos.

"c" se define como int ya que la función regresa un valor numérico entero correspondiente al caracter y así aceptar el caracter especial EOF.

## 2) Modifica main para que sólo se llame una vez a la función getchar()

```
#include <stdio.h>
int main(void){
    int c;
    while( c != EOF){
        c = getchar();
        putchar(c);
    } 
}
```

## 3) Utiliza getchar para escribir un programa que cuente el número de caracteres dado un stdin e imprima este número. Al dar enter (salto de línea) el programa termina. Por ejemplo:

`$echo -e "hola\n" | ./ejecutable.out`

entonces el programa imprime 4:

```
#include <stdio.h>
int main(void){
    int c;
    int cont = 0;

    while( c != '\n'){
        c = getchar();   
        putchar(c);
        cont++;
    } 
    printf("%d\n", cont-1);
}

```

## 4) Modifica el programa de 3) para que cuente el número de líneas dado un archivo de stdin:

`./ejecutable.out < archivo.txt`:


```
#include <stdio.h>
int main(void){
    int c;
    int cont = 0;

    while( c != '\n'){
        c = getchar();   
        putchar(c);
        cont++;
    } 
    printf("%d\n", cont-1);
}

```