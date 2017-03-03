# Tarea 4

--------

## Ejercicio 1

a) Modifica la función longitud_string del siguiente programa siguiendo estos dos pasos:

```
#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
#define CADENA_PRUEBA "Hola a todos"
int longitud_string(char *s){
int i;
i=0;
while(*s != '\0'){
    s = s + 1;
    i++;
}
return i;
}

```

