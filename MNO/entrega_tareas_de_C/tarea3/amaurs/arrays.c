#include <stdio.h>
void printValue(int *pointer,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("p[%d] = %d\n",i, *(pointer + i));
	}
}
void printAdress(int *pointer, int size)
{
	for (int i = 0; i < size; i++)
	{
		//printf("%d\n", size);
		printf("%cp[%d] = %p\n", 38, i, (pointer + i));
	}
}
int main()
{
	int arreglo[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int arreglo2[][3][3] = {{{1,2,3},
	                         {4,5,6},
	                 	     {7,8,9}},
	                 	    {{10,11,12},
	                         {13,14,15},
	                 	     {16,17,18}}};
	printValue(&arreglo[0], sizeof(arreglo) / sizeof(arreglo[0]));
	printAdress(&arreglo[0], sizeof(arreglo) / sizeof(arreglo[0]));
	printValue(&arreglo2[0][0][0], 18);
	printAdress(&arreglo2[0][0][0], 18);

	printf("apuntador %p", arreglo2[0]);
	printf("apuntador %p", arreglo2[1]);
	return 0;
}