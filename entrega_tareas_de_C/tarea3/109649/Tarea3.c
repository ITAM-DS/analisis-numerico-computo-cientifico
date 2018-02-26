#include<stdio.h>

void imprime_reg_impares(int **poin, int n)         // function definition   
{
	int i;
	for(i=1; i<n; i+=2){
		printf("p[%d]: %d\n", i, *poin[i]);
		}
}

void imprime_mems_impares(int **poin, int n)         // function definition   
{
	int i;
	for(i=1; i<n; i+=2){
		printf("p[%d]: %p\n", i, poin[i]);
		}
}



main() 
{
	int i;
	int j;
 //primero se hará un ejemplo con un arreglo unidimensional
	int arreglo[10];
	int matriz[4][3];
	int *poin1[10];
	int *poin2[12];

	for(i=0;i<10;i++){
		arreglo[i] = -i-1;
		poin1[i] = &arreglo[i];
	}

	j = sizeof(arreglo)/sizeof(arreglo[1]);
	printf("Arreglo unidimensional \n");
	imprime_reg_impares(poin1, j);
	printf("\n");
	imprime_mems_impares(poin1, j);
	printf("\n\n");


// se hace un ejemplo con un arreglo de dos dimensiones

	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			matriz[i][j] = -(i+1)*(j+1);
			poin2[i*3+j] = &matriz[i][j];
		}	
	}

	j = sizeof(matriz)/sizeof(matriz[1][1]);

	printf("Arreglo Bidimensional \n");
	imprime_reg_impares(poin2, j);
	printf("\n");
	imprime_mems_impares(poin2, j);
	printf("\n\n");

}