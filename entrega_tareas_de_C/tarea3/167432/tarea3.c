#include <stdio.h>

void funcion1(int *p, int n, int k){
	int j;
	for(j=0; j<n; j++){
	//printf("Entra al for %d\n",j);
	if (j % 2 == 0){
	//printf("La entrada %d no se debería de imprimir\n", j);
	}else{	printf("Usando el apuntador para el valor: arreglo%d[%d]=%d\n",k,j,*(p+j));	}
	}
}

void funcion2(int *p, int n, int k){
	int j;
	for(j=0; j<n; j++){
	//printf("Entra al for %d\n",j);
	if (j % 2 == 0){
	//printf("La entrada %d no se debería de imprimir\n", j);
	}else{	printf("Usando el apuntador para la posición: arreglo%d[%d]=%p\n",k,j,(p+j));	}
	}
}

main(){
//declaración y definición de los arreglos
	int arreglo1[10]; 
	int arreglo2[2][3] = {{-1,-2,-3}, {-4,-5,-6}};
	int i,j;

	printf("Imprimo los arreglos, sus posiciones en memoria y el output de las funciones que utilizan los apuntadores para referencia\n");
	//inicialización del arreglo1:
	for(i=0;i<10;i++){
		arreglo1[i] = -(i+1);
	}
	//Imprimimos el arreglo1

	for(i=0;i<10;i++){
		printf("arreglo1[%d] = %d\n",i,arreglo1[i]);
	}
	//Imprimimos las posiciones de memoria del arreglo1
	for(i=0;i<10;i++){
		printf("arreglo1[%d] = %p\n",i,&arreglo1[i]);
	}
	//Usando el apuntador
	int *p;
	p = arreglo1;
	int n = sizeof(arreglo1) / sizeof(arreglo1[0]);
	int k = 1;
	funcion1(p,n,k);
	funcion2(p,n,k);
 
	//Imprimimos el arreglo2
	for ( i = 0; i < 2; i++ ) {
	for ( j = 0; j < 3; j++ ) {
        printf("arreglo2[%d][%d] = %d\n", i,j, arreglo2[i][j] );
      	}
   	}

	//Imprimimos las posiciones de memoria del arreglo2
	for ( i = 0; i < 2; i++ ) {
	for ( j = 0; j < 3; j++ ) {
        printf("arreglo2[%d][%d] = %p\n", i,j, &arreglo2[i][j] );
      	}
   	}
	
	//Inicializamos los parámetros de las funciones para el caso 2
	p = arreglo2[0];
	n = sizeof(arreglo2) / sizeof(arreglo2[0][0]);
	k = 2;
	funcion1(p,n,k);
	funcion2(p,n,k);








	
}
