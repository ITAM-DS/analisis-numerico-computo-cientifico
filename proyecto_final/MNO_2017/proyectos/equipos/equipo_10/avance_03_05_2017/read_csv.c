#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int** allocate_matrix(int rowMaxIndex, int columnMaxIndex, FILE *fp);
void read_file(FILE *fp, int* rowMaxIndex, int* columnMaxIndex);
int main(int argc, char **argv){

    //CSV file reading
    int rowMaxIndexA, columnMaxIndexA;
	int rowMaxIndexB, columnMaxIndexB;
    int **matA;
	int **matB;
    int i,j,idx;
    char part[1024];
    char *token;
    FILE *fpA, *fpB;
    fpA = fopen("filename.csv","r"); // read mode
    if(fpA == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
	read_file(fpA, &rowMaxIndexA, &columnMaxIndexA);
	matA = allocate_matrix(rowMaxIndexA,columnMaxIndexA, fpA);
	fpB = fopen("filename2.csv","r"); // read mode
    if(fpB == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
	read_file(fpB, &rowMaxIndexB, &columnMaxIndexB);
	matB = allocate_matrix(rowMaxIndexB,columnMaxIndexB, fpB);
}

int** allocate_matrix(int rowMaxIndex,int columnMaxIndex, FILE *fp){
    int idx;
	int **mat;
	int i, j;
	char part[1024];
	char *token;
	// allocate the matrix
    mat=malloc(sizeof(int *) * rowMaxIndex);
	 if (mat == NULL){
        printf("ERROR: out of memory\n");
    }
	for(idx = 0;idx<rowMaxIndex;idx++){
        mat[idx] = malloc(sizeof(int *) * columnMaxIndex);
		if (mat[idx] == NULL){
            printf("ERROR: out of memory\n");
            break;
        }
    }
	
	rewind(fp);
	i = j = 0;
    while(fgets(part,1024,fp) != NULL){
        token = NULL;
        while((token = strtok((token == NULL)?part:NULL,",")) != NULL){
            mat[i][j] = atoi(token);
            j = (j+1)%columnMaxIndex;
        }
        i++;
    }

    fclose(fp);
	return mat;
}

void read_file(FILE *fp, int * rowMaxIndex, int * columnMaxIndex){
	char part[1024];
    char *token;
	int idx;
	*rowMaxIndex = 0;
	*columnMaxIndex=0;
	while(fgets(part,1024,fp) != NULL){
        token = NULL;
		 while((token = strtok((token == NULL)?part:NULL,",")) != NULL){
            if(*rowMaxIndex == 0){ // only want to increment column count on first loop
                *columnMaxIndex=*columnMaxIndex+1;
            }
			for(idx = 0;idx<strlen(token);idx++){
                if(token[idx] == '\n'){ // this assumes there will be a \n (LF) at the end of the line
                    *rowMaxIndex=*rowMaxIndex+1;
                    break;
                }
			}
		 }
	}	
}
