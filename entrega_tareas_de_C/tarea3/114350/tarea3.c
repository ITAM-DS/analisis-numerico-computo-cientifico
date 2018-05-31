#include <stdio.h>

main() 
{
// Arreglo p.

 		int p[10]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
        int *pointer=p;
        int dimension=sizeof(p)/sizeof(p[0]);
        
        printf("\n");
        direcciones(pointer,dimension);
        valores(pointer,dimension);

        printf("\n\n");

// Arreglo multidimensional.

		int arreglo_mult[2][3];
        arreglo_mult[0][0]=-1;
        arreglo_mult[0][1]=-2;
        arreglo_mult[0][2]=-3;
        arreglo_mult[1][0]=-4;
        arreglo_mult[1][1]=-5;
        arreglo_mult[1][2]=-6;
        int *pointer_2 = arreglo_mult[0];
        int dimension_2 = sizeof(arreglo_mult)/sizeof(arreglo_mult[0])+sizeof(arreglo_mult[0])/sizeof(arreglo_mult[0][0])+1;
        
        printf("\n");
        direcciones(pointer_2, dimension_2);
        valores(pointer_2, dimension_2);
}


void valores(int *pointer,int dimension){
        int i;
        for (i=1;i<dimension;i=i+2){
                printf("p[%d]=%d\n",i,*(pointer+i));
        }
}

void direcciones(int *pointer, int dimension){
        int i;
        for (i=1;i<dimension;i=i+2){
                printf("&p[%d]=%p\n",i,(pointer+i));
        }
}