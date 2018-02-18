#include <stdio.h>

void elemimpares(int *apunt,int *dim){
	int i,j;
	int dim1 =*(dim);
	int dim2 = *(dim +1);
	if(dim2 == 0){
		for(i = 0;i < dim1;i++)
			if(i % 2 == 1){
			printf("p[%d]=%d \n",i,*(apunt + i));
			}
	} 
	else{
		for(i = 0;i < dim1;++i)
			for(j=0;j<dim2;j++)
				if((i*dim2+j)%2==1){
					printf("p[%d]=%d \n",i*dim2+j,*(apunt+i*dim2+j));
				}
	}
printf("\n");
}

void direccionesimpares(int *apunt,int *dim){
        int i,j;
        int dim1 = *(dim);
        int dim2 = *(dim +1);
        if(dim2 == 0){
                for(i = 0;i < dim1;i++)
                        if(i % 2 == 1){
                        printf("%cp[%d]: %p \n",38,i,(apunt + i));
                        }
        } 
        else{
                for(i = 0;i < dim1;++i)
                        for(j=0;j<dim2;j++)
                                if((i*dim2+j)%2==1){
                                        printf("%cp[%d]: %p \n",38,i*dim2+j,(apunt+i*dim2+j));
                                }
        }
printf("\n");
}

int main(){
	int array[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int array2[][3]={{-1,-2,-3},{-4,-5,-6}};
	int dim[2]={0};
	int dim1, dim2;
	dim[0]=sizeof(array)/sizeof(array[0]);
	dim1=sizeof(array2)/sizeof(array2[0]);
	dim2=sizeof(array2[0])/sizeof(array2[0][0]);
	elemimpares(&array[0],&dim[0]);
	direccionesimpares(&array[0],&dim[0]);
	dim[1]=dim2;
	dim[0]=dim1;
	elemimpares(&array2[0][0],&dim[0]);
	direccionesimpares(&array2[0][0],&dim[0]);
}

