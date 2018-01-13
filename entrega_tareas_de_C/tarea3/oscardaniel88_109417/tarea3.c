#include <stdio.h>

void printVal (int*,int, int);
void printAdd (int*,int, int);

int main(){
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int array2[2][3] = {{1,2,3},{4,5,6}};
	int length = 0;
	int width = 0;

	length = sizeof(array)/sizeof(array[0]);
	printf("--------------Imprimiendo Valores de Array---------\n\n");
	printVal(&array[0],length, width);
	printf("--------------Imprimiendo Address de Array---------\n\n");
	printAdd(&array[0],length, width);
	length = sizeof(array2)/sizeof(array2[0]);
	width = sizeof(array2[0])/sizeof(array2[0][0]);
	printf("-------------Imprimiendo Valores Arreglo Multi------------------\n\n");
	printVal(&array2[0][0], length, width);
	printf("-------------Imprimiendo Address Arreglo Multi------------------\n\n");
	printAdd(&array2[0][0], length, width);
}

void printVal (int *add, int len, int wid){
	int i,j;
	int cont = 0;
	int n = len;
	if (wid == 0){
		for (i = 0 ; i<n; i++){
			if(i%2 == 1)
				printf("p[%d] = %d \n",i, *(add + i));
		}
	}else{
		for (i=0; i<len; i++){
			for(j=0; j<wid; j++){
				if(cont%2==1){
					printf("p[%d] = %d\n", cont, *(add + cont));
				}
				cont++;
			}
		}
	}
}

void printAdd (int *add, int len, int wid){
        int i,j;
        int cont =0;
        int n = len;
        if (wid == 0){
                for (i = 0 ; i<n; i++){
                        if(i%2 == 1)
                                printf("p[%d] = %p \n",i, add + i);
                }
        }else{
                for (i=0; i<len; i++){
                        for(j=0; j<wid; j++){
                                if(cont%2==1){
                                        printf("p[%d] = %p\n", cont, add + cont);
                                }
				cont++;
                        }
                }
	}
}
