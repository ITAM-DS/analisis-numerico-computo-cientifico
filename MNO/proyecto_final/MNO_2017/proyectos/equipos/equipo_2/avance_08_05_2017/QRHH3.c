#include <stdio.h>
#include <math.h>

void show(double *arr, int row, int col){
 int i,j;
 for (i=0;i<row;i++){
 	for (j=0;j<col;j++){
		printf(" %f",*(arr + (i*col)+j));
	}
	printf("\n");
 }
}

double* vectores(double *arr, int row, int col,int c_actual){
int i,j,k;
int sum_prod_c=0;
int sum_prod_p=0;
double beta=0;
double mu, sigma, v_1,acumula,valor_actualizado;

int vectorc[4]={0,0,0,0}; //Vector completo triangular a partir de diagonal
double vector[4]={0,0,0,0};// Vector con 1 en la diagonal

for (i=0;i<row-c_actual;i++){
	//Vector completo triangular para Calculo de MU
	vectorc[i]=*(arr + ((i+c_actual)*col)+c_actual);
		sum_prod_c+=vectorc[i]*vectorc[i];
	//Calculo de sigma para debajo de la diagonal
	if (i>0) sum_prod_p+=vectorc[i]*vectorc[i];
	// Calculamos el Vector V con V(1)=1
	if (i==0) vector[i]=1; 
	else vector[i]=vectorc[i];	
	printf(" Vector completo: %d \n",vectorc[i]);
	printf(" Vector V : %f \n",vector[i]);
}
	
mu=sqrt(sum_prod_c); // mu= norma del vector completo
sigma=sum_prod_p; // sigma= Producto punto
printf(" MU: %f \n",mu); 
printf(" sigma: %f \n\n",sigma); 

//Calculo del vector householder

if (sigma==0 && vectorc[0]>=0) beta=0;
else if (sigma==0 && vectorc[0]<0) beta=-2;
else
	if (vectorc[0]<=0) v_1=vectorc[0]-mu;
	else v_1=-sigma/(vectorc[0]+mu);
	beta=2*pow(v_1,2)/(sigma + pow(v_1,2));
	vector[0]=v_1;
	 for (i=0;i<row-c_actual;i++){
	 	vector[i]=vector[i]/v_1;
	 	printf(" Vector V de householder : %f \n",vector[i]);
	 }
printf(" \n Beta: %f\n",beta); 
printf(" \n V_1: %f \n\n",v_1);

//Calculo de (I-Bvvt)

double I_Bvvt[4][4]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};	

for (i=0;i<row-c_actual; i++){
	for (j=0;j<row-c_actual; j++){
		if (i!=j) I_Bvvt[i][j]=-1*(beta*vector[i]*vector[j]);
		else I_Bvvt[i][j]=1-(beta*vector[i]*vector[j]);

	}
}

printf("I_Bvvt \n");
show((double *)I_Bvvt,4,4);

// Calculo  (I-Bvvt)* A

for (i=0;i<=4; i++){ // renglones de iBvvt
	for (j=0;j<col; j++){
		for (k=0;k<4; k++){ //columnas de IBvvt
			//*(arr + ((i+c_actual)*col)+c_actual);
			acumula+=((I_Bvvt[j][k]) * (*(arr + k*col+i)));
			printf("arreglo a I_Bvvt: %f\n", I_Bvvt[j][k]);
			printf("arreglo a arreglo : %f\n", (*(arr + k*col+i)));//((i+k)*col)));
			printf("acumula uno : %f\n", acumula );
		}
		valor_actualizado=acumula;
		acumula=0;

	}
	*(arr + (j*col+i))=valor_actualizado;
	
	//*(arr + ((i+c_actual)*col)+c_actual);
	//acumula=0;
	//printf("acumula total: %f\n", acumula );
}
		
	//printf(" vectorc[j] %d",vectorc[j]);

	//*(arr + ((i*col)+c_actual)=acumula;
	//printf("MULTIPLICA %f",acumula);
	printf("acaboooooo \n");
	//acumula=0;



printf("Nuevo Arreglo \n");
show((double *)arr,4,3);
}


void main () {
	int j;
	double A[4][3]={{-1,-1,1},{1,3,3},{-1,-1,5},{1,3,7}};	
	show((double *)A,4,3);
	for (j=0;j<3;j++){
		vectores((double *)A,4,3,j);
}

}

