#include <stdio.h>

void funcion_valores( int *arreglo, int tamanio){
    int i;

    printf("Entradas de impares del arreglo p:\n");
    for(i=1;i<tamanio;i=i+2){
        printf("p[%d]=%d\n", i, arreglo[i]);
    }
}


void funcion_direcciones( int *arreglo, int tamanio){
    int i;

    printf("Direcciones de impares del arreglo p:\n");
    for(i=1;i<tamanio;i=i+2){
        printf("p[%d]=%p\n", i, &arreglo[i]);
    }
}




main(){
    //Definimos variables para el tamaño del vector/matriz
    int tamvec;
    int tammatx,tammaty;

    //Definimos variables de apoyo
    int i,j;

    //Solicitamos ingresar el tamaño del vector
    printf("Ingresa el tamaño del vector p:");
    scanf("%d", &tamvec);
    printf("\n");

    //Definimos el vector con su dimensión
    int p[tamvec];

    //SOlicitamos los valores del vector
    for(i = 0; i < tamvec; i++){
    	printf("Ingresa el valor de p[%d]:", i);
	scanf("%d", &p[i]);
    }
    printf("\n");

    //Usamos las funciones que definimos al inicio para que nos devuelva las entradas del vector y sus direcciones para los impares
    funcion_valores(p,tamvec);
    printf("\n");
    funcion_direcciones(p,tamvec);
    printf("\n");

    //Solicitamos ingresar el tamaño de la matriz
    printf("Ingresa el tamaño 'x' de la matriz p[x][y]:");
    scanf("%d", &tammatx);
    printf("Ingresa el tamaño 'y' de la matriz p[x][y]:");
    scanf("%d", &tammaty);
    printf("\n");

    //Definimos la matriz con sus dimensiones
    int mat[tammatx][tammaty];

    //SOlicitamos los valores de la matriz
    for(i = 0; i < tammatx; i++){
    	for(j = 0; j < tammaty; j++){
        	printf("Ingresa el valor de p[%d][%d]:", i,j);
        	scanf("%d", &mat[i][j]);
    	}
    }
    printf("\n");

    //Usamos las funciones que definimos al inicio para que nos devuelva las entradas de la matriz y sus direcciones para los impares
    funcion_valores(mat[0],tammatx*tammaty);
    printf("\n");
    funcion_direcciones(mat[0],tammatx*tammaty);
    printf("\n");


}
