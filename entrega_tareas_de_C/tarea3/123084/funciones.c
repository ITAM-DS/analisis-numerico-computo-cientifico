#include<stdio.h>

void print_odd_elements(int size,int *pointer){

	int i;
	
	for(int i = 0; i < size; ++i)
	{
		
		if ( i % 2 == 1)
		{
			
			printf("array[%d]: %d\n", i, pointer[i]);
		}
	}

}

void print_odd_pointers(int size,int *pointer){

	int i;
	
	for(int i = 0; i < size; ++i)
	{
		
		if ( i % 2 == 1)
		{
			
			printf("&pointer[%d]: %d, %p\n", i,pointer[i] , &pointer[i]);
		}
	}

}

main()
{
	int tam = 10;
	int tam2 = 6;
	int array [10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int array2 [2][3] = {-1,-2,-3,-4,-5,-6};
	
	int *pointer_1 = array;
	int *pointer_2 = array2;
	printf("va el unidimensional \n");
	print_odd_elements(tam,pointer_1);
	print_odd_pointers(tam,pointer_1);
	printf("va el multidimensional \n");
	print_odd_elements(tam2,pointer_2);
	print_odd_pointers(tam2,pointer_2);
	
}