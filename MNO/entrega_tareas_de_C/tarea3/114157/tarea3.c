#include<stdio.h>
void print_values(int *valor,int n_rows, int n_cols);
void print_position(int *valor,int n_rows, int n_cols);



int main(){
int i,j;


int arreglo[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
int arreglo_mult[][3] = {{-1,-2,-3},{-4,-5,-6}};

printf("\n Imprimir arreglo\n");
int longitud_arreglo = sizeof(arreglo)/sizeof(arreglo[0]);
for(i=0;i<longitud_arreglo;i++){
printf("arreglo[%d]=%d\n",i, arreglo[i]);

}

printf("\n Valores del arreglo \n");
print_values(arreglo, longitud_arreglo, 0);

printf("\n Direcciones del arreglo \n");
for(i=0;i<longitud_arreglo;i++){
printf("arreglo[%d]=%p\n",i, &arreglo[i]);

}

printf("\n Direcciones de memoria pares del arreglo\n");
print_position(arreglo, longitud_arreglo, 0);


printf("\n Imprimir el arreglo multidimensional\n");
int longitud_arreglo_mult = sizeof(arreglo_mult)/sizeof(arreglo_mult[0]);
int num_columnas = sizeof(arreglo_mult[0])/sizeof(arreglo_mult[0][0]);
for(i=0;i<longitud_arreglo_mult;i++){
for(j=0;j<num_columnas;j++)
printf("arreglo_mult[%d][%d] = %d\t", i,j,arreglo_mult[i][j]);
printf("\n");
}


printf("\n Valores del arreglo multidimensional\n");
print_values(&arreglo_mult[0][0],longitud_arreglo_mult,num_columnas);

printf("\n Direcciones del arreglo multidimensional\n");
for(i=0;i<longitud_arreglo_mult;i++){
for(j=0;j<num_columnas;j++)
printf("arreglo_mult[%d][%d] = %p\t", i,j,&arreglo_mult[i][j]);
printf("\n");
}


printf("\n Direcciones de memoria pares del arreglo multidimensional\n");
print_position(&arreglo_mult[0][0],longitud_arreglo_mult,num_columnas);
printf("\n");

return 0;
}



void print_values(int *valor,int n_rows, int n_cols){

int i,j;

if (n_cols==0){

for(i=0;i<n_rows;i++){
if(i%2==1){
printf("*(arreglo[0] + %i) = %i\n", i,*(valor + i));
}
}
}else{
for(i=0;i < n_rows;i++){
for(j=0;j<n_cols;j++){
if((i*n_cols+j)%2==1){
printf("arreglo_mult[%d][%d] = %d\t", i,j,*(valor + i*n_cols + j));
}
}
printf("\n");
}
}

}


void print_position(int *valor,int n_rows, int n_cols){

int i,j;

if (n_cols==0){

for(i=0;i<n_rows;i++){
if(i%2==1){
printf("*(arreglo[0] + %i) = %p\n", i,(valor + i));
}
}
}else{
for(i=0;i < n_rows;i++){
for(j=0;j<n_cols;j++){
if((i*n_cols+j)%2==1){
printf("arreglo_mult[%d][%d] = %p\t", i,j,(valor + i*n_cols + j));
}
}
printf("\n");
}
}

}
