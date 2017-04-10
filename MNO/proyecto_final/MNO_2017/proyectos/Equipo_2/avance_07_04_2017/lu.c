#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
By ZtuX 2012
Metodo LU
tuxo.root@gmail.com
http://ztux.blogspot.mx/
*/

void ShowMatrix(float **Matrix, int n);
void CreateMatrix(float **Matrix, int n);
void Llenar(float **Matrix, int n);
float **SolveGaussJordan(int n, float **MatrixA, float **MatrixB);
 
int main(){
	    int n,i,j,s,k;
	    float **L=NULL,**U=NULL,**A=NULL,Suma=0,Op=0,*Ap,Numer=0,Denom=0;
	        printf("Resolver por mtodo de Factorizacion LU\nIngrese el numero de Variables: ");
	        scanf("%i",&n);
	    //Crear la Matriz A
	    if((A=(float**)malloc(n*sizeof(float*)))==NULL){
	        printf("[!] Insuficiente espacio en la Memoria\n");
	        return -1;
	    }
	        A=(float**)malloc((n)*sizeof(float));
	        for(i=0;i<n+1;i++){
	        A[i]=(float*)malloc(sizeof(float));
	        }
	    /*Creamos la Matriz L*/
	    if((L=(float**)malloc(n*sizeof(float*)))==NULL){
	        printf("[!] Insuficiente espacio en la Memoria\n");
	        return -1;
	    }
	    L=(float**)malloc(n*sizeof(float));
	    for(i=0;i<n;i++){
	        L[i]=(float*)malloc(n*sizeof(float));
	    }
	    /*CREAR LA MATRIZ U*/
	    if((U=(float**)malloc(n*sizeof(float*)))==NULL){
	        printf("[!] Insuficiente espacio en la Memoria\n");
	        return -1;
	    }
	    U=(float**)malloc(n*sizeof(float));
	    for(i=0;i<n;i++){
	        U[i]=(float*)malloc(n*sizeof(float));
	    }
	    //Introducimos Valores a A
	        for(i=0;i<n;i++){
	        for(j=0;j<n+1;j++){
	            printf("Introduce el valor [%i][%i]: ",i,j);
	            scanf("%f",&A[i][j]);
	        }
	        }
	        //MOSTRAMOS SISTEMA ECUACIONES
	        printf("MATRIZ QUE REPRESENTA A EL SISTEMA DE ECUACIONES\n");
	        for(i=0;i<n;i++){
	            printf("[");
	        for(j=0;j<n+1;j++){
	            printf("\t%0.2f\t",A[i][j]);
	            if (j==n-1) printf("|");
	        }
	        printf("]\n");
	        }
	        //LENAR MATRICES DE CEROS
	        Llenar(U,n);
	        Llenar(L,n);
	        Ap=&Suma;//Apuntamos a Suma
	        //[!]AQUI EMPIEZA EL CALCULO DE LAS MATRICES L y U
	        //DESDE k=1 HASTA n
	        for(k=0;k<n;k++){
	            U[k][k]=1;
	            //SUMATORIA
	            for(s=0;s<=(k-1);s++){
	            Op=L[k][s]*U[s][k];
	            Suma+=Op;
	            }
	            //FIN SUMATORIA
	            L[k][k]=A[k][k]-Suma;
	            *Ap=0;
	            //DESDE i=(k+1) HASTA n
	            for(i=(k+1);i<n;i++){
	                //SUMATORIA
	            for(s=0;s<=(k-1);s++){
	                Op=L[i][s]*U[s][k];
	                Suma+=Op;
	            }
	            //FIN SUMATORIA
	            L[i][k]=A[i][k]-Suma;
	            *Ap=0;
	            }
	            //FIN
	            //DESDE j=(k+1) HASTA n
	            for(j=(k+1);j<n;j++){
	                //SUMATORIA
	            for(s=0;s<=(k-1);s++){
	                Op=L[k][s]*U[s][j];
	                Suma+=Op;
	            }
	            //FIN SUMATORIA
	                Numer=A[k][j]-Suma;
	                Denom=L[k][k];
	            U[k][j]=Numer/Denom;
	            *Ap=0;
	            }
	            //FIN
	        }//FIN
	        //[!]AQUI TERMINA EL CALCULO DE LAS MATRICES L y U
	    printf("\nMatriz L:\n");
	        ShowMatrix(L,n);
	        printf("\nMatriz U:\n");
	        ShowMatrix(U,n);
	        //[!]RESOLVEREMOS LOS SISTEMAS DE ECUACIONES CON GAUSS-JORDAN
	        //Ly=B  y depues PARA Ux=y y Se mostraran los valores de las incognitas =)
	        printf("\n[+]Resolviendo Ly=b:\n");
	        A=SolveGaussJordan(n,L,A); //Apuntamos la matriz que nos regresa a la Matriz A Nueva =)
	        printf("\n[+]Resolviendo Ux=y:\n");
	        SolveGaussJordan(n,U,A); // Se mostrara la matriz solucion al Sistema de Ecuaciones =)
	        //LIBERAR MEMORIA
	        for(i=0;i<n;i++){
	        free(A[i]);
	        free(L[i]);
	        free(U[i]);
	        }
	    free(A);
	        free(L);
	        free(U);
	        return 0;
	}
	 
	void ShowMatrix(float **Matrix, int n){
	    int i,j;
	    for(i=0;i<n;i++){
	        printf("[");
	        for(j=0;j<n;j++) printf(" %0.2f ",Matrix[i][j]);
	        printf("]\n");
	    }
	}
	 
	void CreateMatrix(float **Matrix, int n){
	    int i,j;
	        for(i=0;i<n;i++){
	        for(j=0;j<n;j++){
	            printf("Introduce el valor [%i][%i]: ",i,j);
	            scanf("%f",&Matrix[i][j]);
	        }
	        }
	}
 
	void Llenar(float **Matrix, int n){
	    int i; for(i=0;i<n;i++) memset(Matrix[i],0,n*sizeof(float));
	}
	 
	float **SolveGaussJordan(int n, float **MatrixA, float **MatrixB){
	    float **A, apoyo;
	    int i, j, k;
	    float matapoyo[n+1];
	    A=(float**)malloc(sizeof(float*)*n);
	    for(i=0;i<n+1;i++){
	        A[i]=(float*)malloc(sizeof(float)*n);
	    }
	    for(i=0;i<n;i++){
	        for(j=0; j<n+1; j++){
	            if(j<=n-1) A[i][j]=MatrixA[i][j];
	            else A[i][j]=MatrixB[i][j];
	        }
	    }
	    printf("\t[-]Matriz ques representa el sistema:\n");
	    for(i=0;i<n;i++){
	        printf("[ ");
	        for(j=0; j<n+1; j++){
	            printf("\t%.2f\t", A[i][j]);
	            }
	        printf(" ]\n");
	    }
	 
	    for(i=0;i<n;i++){
	        k=1;
	        do{
	            apoyo=A[i][i];
	            if(apoyo==0){
	                for(j=0; j<n+1; j++){
	                    matapoyo[j]=A[i][j];
	                }
	                for(j=0; j<n+1; j++){
	                   A[i][j]=A[i+k][j];
	                }
	                for(j=0; j<n+1; j++){
	                   A[i+k][j]=matapoyo[j];
	                }
	            }
	            k++;
	        }while(apoyo==0);
	 
	    for(j=0;j<n+1;j++) A[i][j]=A[i][j]/apoyo;
	 
	    for(j=0;j<n+1;j++){
	        if(i!=j){
	            apoyo=-1*A[j][i];
	            for(k=0; k<n+1; k++){
	                A[j][k]=A[j][k]+(apoyo*A[i][k]);
	            }
	        }
	    }
	    printf("\n");
	    for(j=0;j<n;j++){
	        printf("[ ");
	        for(k=0; k<n+1; k++){
	            printf("\t%.2f\t", A[j][k]);
	        }
	        printf(" ]\n");
	      }
	    }
	    return A;
}

