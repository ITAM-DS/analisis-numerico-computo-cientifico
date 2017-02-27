#include<stdio.h>
//Análisis númerico cómputo científico
//Tarea 3
//160314: Paulina Lisett Salgado Figueroa

void impValor(int *p, int dim);
void impDir(int *p, int dim);

int main(){
    int arreglo[10]; 
    int arreglo_mult[2][3]; 
    int i,j,k=0;
    int colum,ren,dim; 
    void *puntero;
  //inicialización del los arreglos:
    for(i=0;i<10;i++){
        arreglo[i] =-(i+1);
    }
    
    for(i=0;i<2;i++){
       for (j=0;j<3;j++){ 
       arreglo_mult[i][j] =-(k+1);
       k=k+1;   	
    }
   
  }

  //Arreglo unidimensional
  ren=sizeof(arreglo)/sizeof(*arreglo);
  dim=ren*1;
  printf("\n\nArreglo unidimensional\n");
  puntero=&arreglo;
  printf("Imprime valores\n") ;
  impValor(puntero,dim);
  printf("\nImprime direcciones\n") ;
  impDir(puntero,dim); 
  
  //Arreglo multidimensional
  ren=sizeof(arreglo_mult)/sizeof(*arreglo_mult);
  colum=sizeof(arreglo_mult[0])/sizeof(arreglo_mult[0][0]); 
  dim=ren*colum;
  puntero=&arreglo_mult;
  
  printf("\n\nArreglo multidimensional\n");
  printf("Imprime valores\n") ;
  impValor(puntero,dim);
  printf("Imprime direcciones\n") ;
  impDir(puntero,dim);


}

//Definición de funciones
void impValor(int *p, int dim){
    int i;
    for(i=0;i<dim;i++){
      if (i%2==1){  
      printf("p[%d] = %d\n",i,*(p+i));
      	
      }
     }   
  }  
   

void impDir(int *p, int dim){
    int i;
    for(i=0;i<dim;i++){
      if (i%2==1){  
      printf("p[%d] = %p\n",i,(p+i));	
      }
     }   
  }  
    
 
