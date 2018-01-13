#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

    //CSV 
    int rowMaxIndex,columnMaxIndex;
    int **mat;
    int *matc;
    int i,j,idx;

    char part[1024];
    char *token;
    FILE *fp;
    fp = fopen("filename.csv","r"); // modo lectura
    if(fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    // contamos cuantos renglones y columnas hay en el archvio
    rowMaxIndex = 0;
    columnMaxIndex = 0;
    while(fgets(part,1024,fp) != NULL){
        token = NULL;

        while((token = strtok((token == NULL)?part:NULL,",")) != NULL){
            if(rowMaxIndex == 0){ 
                columnMaxIndex++;
            }
            for(idx = 0;idx<strlen(token);idx++){
                if(token[idx] == '\n'){ 
                    rowMaxIndex++;
                    break;
                }
            }
        }
    }

    // alocamos la matriz
    matc = malloc(rowMaxIndex*columnMaxIndex*sizeof(int));
    mat = malloc(rowMaxIndex*sizeof(int*));

    for(idx = 0;idx<rowMaxIndex;idx++){
        mat[idx] = matc+idx*columnMaxIndex;
    }

    // regresamos al inicio del archivo
    rewind(fp);

    // leemos y cargamos datos
    i = j = 0;
    while(fgets(part,1024,fp) != NULL){
        token = NULL;
        while((token = strtok((token == NULL)?part:NULL,",")) != NULL){
            mat[i][j] = atoi(token);
            j = (j+1)%columnMaxIndex;
        }
        i++;
    }
	for (i=0; i<rowMaxIndex;i++){
		for (j=0; j<columnMaxIndex; j++){
			printf("mat[%d][%d] %d",i,j,mat[i][j]);
		}
		printf("\n");
	}

    fclose(fp);
    return 0;
}
