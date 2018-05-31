#include<stdio.h>
//
// Imprime los valores
//
void fun1 (int * ptr, int dmn) {
	for (int i = 1; i < dmn; i = i + 2 ){
		printf("Valor de la posición %d: %d\n", i, *(ptr + i));
	}


}
//
// Imprime las direcciones
//
void fun2 (int * ptr, int dmn) {
	for (int i = 1; i < dmn; i = i + 2 ){
		printf("Dirección de la posición %d: %p\n", i, (ptr + i));
	}
}

main(){
// Vector
int p[10];
//
// Inicializo el vector
//

for( int i = 0; i < 10; i++){
	p[i] = -i - 1;
}
//
// Dirijo el apuntador
//
int *ptr = p;
//
// Llamo las funciones
//
fun1 (ptr, 10);
fun2 (ptr, 10); 
//
// Inicializo la matriz para que quede igual al ejemplo de la tarea
//
int k = -1;
int q[2] [3];
	for( int i = 0; i < 2; i++) {
		if (i > 0) {k = -3 * i;}
		for ( int j = 0; j < 3; j++){
			q[i][j] = - i  - j + k; 
		}
	}
//
// Dirijo el apuntador
//
int *ptr2 = q[0];
//
// Llamo las funciones
//
fun1 (ptr2, 6);
fun2 (ptr2, 6); 

}


	
