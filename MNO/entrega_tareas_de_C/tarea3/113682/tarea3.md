#Tarea 3

Realiza un programa en el que se impriman las entradas impares de un arreglo y las direcciones de memoria también en las posiciones impares.
Define dos funciones que realicen las impresiones de pantalla. Las funciones como mínimo reciben un apuntador y fucionan para arreglos de una dimensión y de dos dimensiones.

## Función 1
### Imprime las entradas impares de un arreglo 

```
void fun1(int *apuntador, int dim){
	int i;
	for(i=0; i<dim; i++)
		printf("arreglo[%d] = %d\n", 2*i+1, *(arreglo + 2*i+1));
}
```	
## Función 2
### Imprime la dirección de memoria de las posiciones impares de un arreglo

```
void fun2(int *apuntador, int dim){
	int i;
	for(i=0; 2*i+1<dim; i++)
		printf("&arreglo[%d] = %p\n", 2*i+1, apuntador+(2*i+1));
}
```
