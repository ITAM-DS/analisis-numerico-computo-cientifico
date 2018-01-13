
#include <stdio.h>

void imp_val(int *val, int tam, int dim);
void imp_apun(int *val, int tam, int dim);

int main()
{
	int arreglo[][3] = {{11,12,13},{1,2,3}};
	int arreglo2[3] = {11,12,13};

	imp_val(&arreglo[0][0], sizeof(arreglo[0])/sizeof(int), sizeof(arreglo)/sizeof(arreglo[0]));
	imp_apun(&arreglo[0][0], sizeof(arreglo[0])/sizeof(int), sizeof(arreglo)/sizeof(arreglo[0]));

	imp_val(&arreglo2[0], sizeof(arreglo2[0])/sizeof(int), sizeof(arreglo2)/sizeof(arreglo2[0]));
	imp_apun(&arreglo2[0], sizeof(arreglo2[0])/sizeof(int), sizeof(arreglo2)/sizeof(arreglo2[0]));

	return 0;
}

void imp_val(int *val, int tam, int dim){
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if ((i+j)%2==0)
			{
				printf("Valor[%d][%d]: %d\n", i, j, *(val+i+j*tam));
			}
		}
	}
}

void imp_apun(int *val, int tam, int dim){
	for (int i = 0; i < tam; i++)
	{

	for (int j = 0; j < dim; j++)
	{
		if ((i+j)%2==0)
		{
			printf("Apuntador[%d][%d]: %#010x\n", i, j, val+i+j*tam);
		}
	}
}
}