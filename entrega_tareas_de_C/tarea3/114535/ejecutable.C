/* Tarea 3 114535 */

#include <stdio.h>

// Function to print elements in odd positions
void values(int row_n, int col_n, int *r);

// Function to print address of elements in odd positions
void addresses(int row_n, int col_n, int *r);

int main(){
	// define 2d array
	int col_n, row_n, a, b;
	printf("Enter the number of columns: \n");
	scanf("%d", &col_n);
	printf("Enter the number of rows: \n");
	scanf("%d", &row_n);

	int r[row_n][col_n];
	
	// fill it with the user input
	for (a=0; a<row_n; a++){
		for (b=0; b<col_n; b++){
			printf("Enter the element (row: %d,  col: %d) of the 2d array \n", a+1, b+1);
			scanf("%d",&r[a][b]);
		}
	}
	values(row_n, col_n, r[0]);
	addresses(row_n, col_n, r[0]);
}

void values(int row_n, int col_n, int *r){
	int i=0, j=0;
	int k=0;
        printf("\n\nElements at the odd position:\n");
	for (i = 0; i < col_n; i++){
      		for (j = 0; j < row_n; j++){
			//printf("valor de k %d \n", k);
			if (k % 2 == 1){
                       		printf("p[%d] %d \n ", k, r[k]);
			}
                	k++;
		}
	}
}

void addresses(int row_n, int col_n, int *r){
	int i=0, j=0;
	int k=0;
        printf("\n\nElements at the odd position:\n");
	for (i = 0; i < col_n; i++){
      		for (j = 0; j < row_n; j++){
			//printf("valor de k %d \n", k);
			if (k % 2 == 1){
                       		printf("p[%d] %p \n ", k, &r[k]);
			}
                	k++;
		}
	}
}
