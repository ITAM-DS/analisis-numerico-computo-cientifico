# include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>


#define MAX_VAL 50
#define MIN_VAL 10

int main(int argc,char *argv[])
{
FILE* fp;
char *name=argv[3];
//printf("Enter the name of the matrix : ") ;
//scanf("%s", name) ;
fp = fopen(name, "w+");

int mat[1100][1100] ;
int i, j;
int row=atoi(argv[1]);
int col=atoi(argv[2]);


//Random seed
	srandom(time(0)+clock()+random());

#pragma omp parallel for private(i,j) shared(mat)
for(i = 0 ; i < row ; i++)
  for(j = 0 ; j < col ; j++)
    mat[i][j] = rand() % MAX_VAL + MIN_VAL;;
//printf("\n\nThe elements in the matrix are: \n\n") ;
for(i = 0 ; i < row ; i++){
  for(j = 0 ; j < col ; j++){
    fprintf(fp,"%d", mat[i][j]) ;
    fprintf(fp,"\t");
  }
  fprintf(fp,"\n");
}
fclose(fp);
}
