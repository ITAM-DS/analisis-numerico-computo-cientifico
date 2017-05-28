#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#include <math.h>
static int i,j;
extern double beta,v_1;

void inicializa_matriz(mat p, char *s){
	int m = renglones(p);
	int n = columnas(p);
	FILE * pFile;
  	pFile = fopen (s,"r");
  	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			fscanf(pFile,"%lf", &entrada(p,i,j));
	fclose(pFile);
}

void inicializa_vector(vect p, char *s){
	int m = renglones_vector(p);
	FILE * pFile;
  	pFile = fopen (s,"r");
  	for(i=0;i<m;i++)
			fscanf(pFile,"%lf", &entrada_vector(p,i));
	fclose(pFile);
}

 void inicializa_submatriz(mat p,mat2 p2,int k){
 	int mr = renglones_mr(p2);
	int nr = columnas_nr(p2);
 	int m = renglones(p);
	int n = columnas(p);
	printf("Submatriz A:\n");
		for(i=0;i<mr;i++){
			for(j=0;j<nr;j++){
				entrada2(p2,i,j)=entrada(p,i+k,j+k);
				if(j<nr-1)
				printf("matriz[%d][%d]=%.5f\t",i,j,entrada2(p2,i,j));
				else
				printf("matriz[%d][%d]=%.5f\n",i,j,entrada2(p2,i,j));

			}
		}
}

void imprime_matriz(mat p){
	int m = renglones(p);
	int n = columnas(p);
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(j<n-1)
				printf("matriz[%d][%d]=%.5f\t",i,j,entrada(p,i,j));
				else
				printf("matriz[%d][%d]=%.5f\n",i,j,entrada(p,i,j));
			}
		}
}

void imprime_vector(vect p){
	int m = renglones_vector(p);
			for(i=0;i<m;i++)
				printf("vector[%d]=%.5f\n",i,entrada_vector(p,i));
}

double* mcol(mat p, double *v, int lon_vector, double *mu,double *sigma){	
	for (i = 0; i < lon_vector; i++){
		mu[0] += v[i] * v[i];
		if (i>0) sigma[0] += v[i] * v[i];	
	}
	mu[0]=sqrt(mu[0]);
	return  mu,sigma;
}

double* vectorHH(mat p, double *v, double *mu,double *sigma, double *vhh,int lon_vector){
	beta=0,v_1=0;
	int m = renglones(p);

	if (sigma[0]==0 && v[0]>=0) beta=0;
	else if (sigma==0 && v[0]<0) beta=-2;
	else{
		if (v[0]<=0) v_1=v[0]-mu[0];
		else v_1=(-1*sigma[0])/(v[0]+mu[0]);
		
		beta=2*pow(v_1,2)/(sigma[0] + pow(v_1,2));
		v[0]=v_1;
		 for (i=0;i<lon_vector;i++){
		 	vhh[i]=v[i]/v_1;
		 	printf("Vector householder[%d]:%.5f\n",i,vhh[i]);
		 }
	}
	return vhh;
}

double* I_Bvvt(double *vhh,double beta, mat3 p3){
 	int mh = renglones_mh(p3);
	int nh = columnas_nh(p3);
	for (i=0;i<mh; i++){
		for (j=0;j<nh; j++){

			if (i!=j) entrada3(p3,i,j)=-1*(beta*vhh[i]*vhh[j]);
			else entrada3(p3,i,j)=1-(beta*vhh[i]*vhh[j]);

		}
	}	printf("\nCálculo de (I-Bvvt): \n");
			for(i=0;i<mh;i++){
				for(j=0;j<nh;j++){
					if(j<nh-1)
					printf("I-Bvvt[%d][%d]=%.5f\t",i,j,entrada3(p3,i,j));
					else
					printf("I-Bvvt[%d][%d]=%.5f\n",i,j,entrada3(p3,i,j));
				}
			}
}

 
double* matrix_mul(mat p, mat3 p3, mat2 p2, int k){
	int m = renglones(p);
	int n = columnas(p);

	int mh = renglones_mh(p3);
	int nh = columnas_nh(p3);
	int mr = renglones_mr(p2);
	int nr = columnas_nr(p2);
	double valor=0; 
	int i, j, g;
	for (j = 0; j < nr; j++){
		for (i = 0; i < mh; i++){
			for (g = 0; g < nh; g++){
				//printf("matriz h[%d][%d]=%.5f\n",i,g,entrada3(p3,i,g));
				//printf("matriz A[%d][%d]=%.5f\n",g,j,entrada2(p2,g,j));
				valor+=  entrada3(p3,i,g)*entrada2(p2,g,j);
			}
			entrada(p,i+k,j+k)=valor; //sobreesribimos a A
			//printf("\n valor %f\n ",valor);
			valor=0;
		}
	}
			printf("\nCálculo de (I-Bvvt)*A: \n");
			imprime_matriz(p);
}


double* factor_form_Q(mat p, double *vhh, int lon_vector, int k){
	int m = renglones(p);
	int n = columnas(p);
	for (i=1;i<lon_vector;i++){
		entrada(p,i+k,k)=vhh[i];
	}
	printf("\nFactor Form Q y R: \n");
	imprime_matriz(p);
	printf("------------\n");
}

double* MC(mat p, vect y){
	int m = renglones(p);
	int n = columnas(p);
	int k,i,j;
	double beta;
	double *vectorv= (double *)malloc(sizeof(double)*m);

	for (k = 0; k < n; k++) {
		vectorv = realloc(vectorv,sizeof(double)*(m-k));
		for(i=0; i < m-k; i++) {
  			if (i==0) vectorv[i] = 1;
  			else vectorv[i] = entrada(p,i+k,k);
	  		printf("Vector v[%d]=%.5f\n",i,vectorv[i]);
	  		beta += vectorv[i]*vectorv[i];	
		}
		beta = 2/beta;
	  	printf("Beta=%.5f\n",beta);
		printf("------------\n");
		beta = 0;
	}
}

