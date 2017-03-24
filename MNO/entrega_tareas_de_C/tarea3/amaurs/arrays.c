#include <stdio.h>
void printValue(int *pointer,int size)
{
	for (int i = 1; i < size; i+=2)
	{
		printf("p[%d] = %d\n",i, *(pointer + i));
	}
}
void printAdress(int *pointer, int size)
{
	for (int i = 1; i < size; i+=2)
	{
		printf("%d", size);
		printf("%cp[%d] = %p\n", 38, i, (pointer + i));
	}
}
int main()
{
	int arreglo[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int arreglo2[][3] = {{-1,-2,-3},
	                     {-4,-5,-6}};
	printValue(&arreglo[0], sizeof(arreglo) / sizeof(arreglo[0]));
	printAdress(&arreglo[0], sizeof(arreglo) / sizeof(arreglo[0]));
	printValue(&arreglo2[0][0], (sizeof(arreglo2) / sizeof(arreglo2[0])) * (sizeof(arreglo2[0]) / sizeof(arreglo2[0][0])));
	printAdress(&arreglo2[0][0], (sizeof(arreglo2) / sizeof(arreglo2[0])) * (sizeof(arreglo2[0]) / sizeof(arreglo2[0][0])));
	return 0;
}