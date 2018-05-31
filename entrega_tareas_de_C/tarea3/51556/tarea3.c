#include<stdio.h>



void val(int *p, int dim){
    int j;
    for(j=0;j<dim;j++){
      if (j%2==1){  
      printf("p[%d] = %d\n",j,*(p+j));
      	
      }
     }   
  }  
   

void dir(int *p, int dim){
    int i;
    for(i=0;i<dim;i++){
      if (i%2==1){  
      printf("p[%d] = %p\n",i,(p+i));	
      }
     }   
  }



void main(){
    int arr[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10}; 
    int arrm[2][3] = {{-1,-2,-3},{-4,-5,-6}}; 
    int col;
    int tam; 
    int dim; 
    void *apun;

  
  printf("\n\nuna dimension\n");
 
  tam=sizeof(arr)/sizeof(*arr);
  dim=tam*1;
  apun=&arr;

 
  val(apun,dim);

 printf("\n\n-------------------\n"); 

  dir(apun,dim); 
  
  
  tam=sizeof(arrm)/sizeof(*arrm);
  col=sizeof(arrm[0])/sizeof(arrm[0][0]); 

  dim=tam*col;
  apun=&arrm;
  
  printf("\n\n 2 dimensiones\n");

  val(apun,dim);
 
 printf("\n\n-------------------\n");
  
  dir(apun,dim);


}


  
    
 
