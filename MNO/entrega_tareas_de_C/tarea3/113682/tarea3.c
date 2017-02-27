#include <stdio.h>

void fun1(int *apuntador, int dim){
	int i;
	for(i=0; 2*i+1<dim; i++)
		printf("arreglo[%d] = %d\n", 2*i+1,*(apuntador+(2*i+1)));
}

void fun2(int *apuntador, int dim){
	int i;
	for(i=0; 2*i+1<dim; i++)
		printf("&arreglo[%d] = %p\n", 2*i+1,(apuntador+(2*i+1)));
}
main(){
	int arreglo[10];
	int i,j, dim2, row, col;
	int dim1 = sizeof(arreglo)/sizeof(arreglo[0]);
	int arreglo2[7][3];

//arreglo dimensión 1
	for(i=0; i<dim1; i++)
		arreglo[i] = i+8;
	printf("Entradas del arreglo dimensión 1\n");
	fun1(arreglo,dim1);
	printf("Dirección de memoria del arreglo dimensión 1\n");
	fun2(arreglo, dim1);
//arreglo dimensión 2
	row = sizeof(arreglo2)/sizeof(arreglo2[0]);
	col = sizeof(arreglo2[0])/sizeof(arreglo2[0][0]);
	dim2 = row*col;
	for(i=0; i<row; i++){
		for(j=0;j<col;j++)
			arreglo2[i][j] = -(j+i+1);
	}
	printf("Entradas del arreglo dimensión 2\n");
	fun1(arreglo2,dim2);
	printf("Dirección de memoria del arreglo dimensión 2\n");
	fun2(arreglo2, dim2);

}

	
