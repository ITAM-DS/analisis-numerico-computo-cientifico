#include<stdio.h>

// función para imprimir los impares del arreglo:

void valores(int *p, int dim){
    int j;
    for(j=0;j<dim;j++){
      if (j%2==1){  
      printf("p[%d] = %d\n",j,*(p+j));
      	
      }
     }   
  }  
   
// función para imprimir las posiciones de memoria impares del arreglo:


void direct(int *p, int dim){
    int i;
    for(i=0;i<dim;i++){
      if (i%2==1){  
      printf("p[%d] = %p\n",i,(p+i));	
      }
     }   
  }


//Hacemos el main:

main(){
        int i,j;
	int arreglo1[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10}; 
	int arreglo2[2][3] = {{-1,-2,-3}, {-4,-5,-6}};

// Para el arreglo 1:
	int *p;
	p = arreglo1;
	int n = sizeof(arreglo1) / sizeof(arreglo1[0]);
	valores(p,n);
	direct(p,n);
//Para el arreglo 2:
	int *q; 
        q = arreglo2[0];
	int m = sizeof(arreglo2) / sizeof(arreglo2[0][0]);
	valores(q,m);
	direct(q,m);

	
}
