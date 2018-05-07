#include <stdio.h>
#include <math.h>
#include<omp.h>

int main(void){
	int m, n, i, j;

	printf("Ingresa el número de filas de matriz:");
    	scanf("%d", &m);
    	printf("Ingresa el número de columnas de la matriz:");
    	scanf("%d", &n);

	
	float A[m][n], B[m][n];

	//Leemos la matriz, columna por columna
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("Ingresa el valor %d de la fila %d:", j, i);
			scanf("%f", &A[i][j]);
			 
		}
	}
	printf("\n");


	//Imprimimos la matriz A
	printf("Imprimimos la matriz A\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%f\t", A[i][j]);
		
		}
		printf("\n");
	}
	printf("\n");

	#pragma omp parallel for num_threads(m)
		for(i = 0; i < m; i++){
			#pragma omp parallel for num_threads(n)
				for(j = 0; j < n; j++){
					B[i][j] = A[i][j];	
				}
		}	

	//Imprimimos la matriz B
	printf("Imprimimos la matriz B\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%f\t", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");

return 0;
}

