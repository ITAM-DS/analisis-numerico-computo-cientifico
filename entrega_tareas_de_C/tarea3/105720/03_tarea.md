


# Tarea 3

---

**CU:** 105720

**Nombre:** Sonia Mendizábal Claustro

---

>Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares. 

El programa se encuentra en el archivo 03_tarea.c

>Define dos funciones que realicen las impresiones en pantalla. Las funciones como mínimo reciben un apuntador y funcionan para arreglos de una dimensión y de dos dimensiones.

Las dos funciones que realizan las impresiones para los dos tipos de arreglos son los siguientes. 

La función `print_array` imprime los elementos del arreglo.
```
void print_array(int *elems, int *arreglo){
    int pos, i, j;
    
    for(pos = 0; pos < elems; pos++){
        if ( (pos % 2) == 1 ){
                printf("posicion %d valor: %d\n", pos, *(arreglo+pos));
            }
        }
}
```

La función `print_pos` imprime las posiciones del arreglo. En esta 
función la única diferencia es el tipo de variable indicado 
en la función printf `%p`.
```
void print_pos(int *elems, int *arreglo){
    int pos, i, j;
    
    for(pos = 0; pos < elems; pos++){
        if ( (pos % 2) == 1 ){
                printf("posicion %d dirección: %p\n", pos, *(arreglo+pos));     
            }
        }
}
```

