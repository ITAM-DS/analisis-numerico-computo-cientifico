/* Autores: 
* Walter Martínez Santana
* José Carlos Castro
*
*Cholesky en Paralelo en CUDA
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

__global__ void multMatriz(float *da, float *db, float *dc, int num){
	float sum=0;
	int j = threadIdx.x + blockIdx.x * blockDim.x;
	int i = threadIdx.y + blockIdx.y * blockDim.y;
	while(j<num){
		while(i<num){
			for (unsigned int k = 0; k<num; k++)
				sum += da[i * num + k] * db[k * num + j];
			dc[i*num + j] = (float) sum;
			i += gridDim.y * blockDim.y;
		}
		j+=gridDim.x * blockDim.x;
		i = threadIdx.y + blockIdx.y * blockDim.y;
	}
	
}

__global__ void indices(){
	int id=threadIdx.x + blockIdx.x*blockDim.x;
	printf("blockdimy: %d  threadx: %d  Blockidx: %d  blockdimx: %d id:  %d raiz: %f\n",
	blockDim.y,threadIdx.x , blockIdx.x,blockDim.x, id,sqrt((double)id));
	__syncthreads();
	
}

__global__ void choleskyParalelo(float *db, int num){
	int id=threadIdx.x + blockIdx.x*blockDim.x;
	int x=0;
	int inicio=0;
	int k=0, N=num;
	int id1=id+inicio, ids=id,id2;
	int N2 = N;
	int NN=0, KK=0;
	
	while(k < N){
		id1=id+inicio;
		//Checamos si es un elemnto de la diagonal
		if(id1 == inicio){
			db[id1] = sqrt(db[id1]);
		}else //si no es elemento de la diagonal, lo dividimos por el elemento diagonal de su columna
		{
			x=0;
			while(id1 <N2){
			
				while(x<1000)
					x++;
				__syncthreads();	
				db[id1] = db[id1]/db[inicio];
				
				id1 += gridDim.x * blockDim.x;
			__syncthreads();
			}
			//__syncthreads();//hacemos que todos los threads esperen a los que faltan
			
			
		}__syncthreads();
		//id=ids;
		inicio += (N-k); //Preparo el siguiente salto al siguiente elemento diagonal
		
		
		NN = N2; //Empiezo actaulizar valores de las columnas restantes a la actualizada
		KK = k+1;//cada columna posterior tiene 1 elemento menos a la anterior
		
		while(NN < (int)N*(N+1)/2){
			id2=id + NN; // saltamos a la siguiente columna
			while(id2 < NN + (N-KK)){
				db[id2] = db[id2] -db[id + KK]* db[KK];
				 
				id2 += gridDim.x * blockDim.x;
				__syncthreads();
			}
			//__syncthreads();
			
			NN += (N-KK);
			KK++;
		
		}
		//__syncthreads();
		k++; //pasamos a la siguiente columna
		N2 += (N-k); //Siguiente elemento diagonal
		__syncthreads();
		
	
	}	
	
}

#define n 5
#define SIZE n*n*sizeof(float)

int main(){

	int N=n,i,j;
	float *A, *B, *C;
	float *da, *db, *dc;
	int m, P=1,U=6;
	srand(time(NULL));
	
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);	
	dim3 dimGrid(16, 16);
	dim3 dimBlock(16, 16);
	
	A=(float *)malloc(SIZE);
	B=(float *)malloc(SIZE);
	C=(float *)malloc(SIZE);
	for(m=0;m<N*N;m++){
		A[m]=(float)P+(int)(((U-P+1.0)*rand())/(RAND_MAX+1.0));
		//B[m]=(float)P+(int)(((U-P+1.0)*rand())/(RAND_MAX+1.0));
		C[m]=(float)0;
	}
	
	//Transpuesta de A
	for( i = 0;i<N;i++)
		for(j=0;j<N;j++)
			B[j + i*N] = A[i + j*N];
	
	cudaMalloc((void**)&da, SIZE);
	cudaMalloc((void**)&db, SIZE);
	cudaMalloc((void**)&dc, SIZE);
	
	cudaMemcpy(da,A, SIZE, cudaMemcpyHostToDevice);
	cudaMemcpy(db,B, SIZE, cudaMemcpyHostToDevice);
	cudaMemcpy(dc,C, SIZE, cudaMemcpyHostToDevice);
	
	cudaEventRecord(start, 0);
	multMatriz<<<dimGrid , dimBlock >>>(da,db,dc,N);
	//cudaThreadSynchronize();
	cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
	
	cudaMemcpy(C,dc, SIZE, cudaMemcpyDeviceToHost);
	
	cudaFree(da);
	cudaFree(db);
	cudaFree(dc);
	free(B);
	
	
	//Optimizacion de memoria
	//Almacenamos la parte debajo de la diagonal y la diagonal de la matriz
	int nuevoSize = N*(N+1)/2;
	
	j=0;
	int k;
	B=(float *)malloc(nuevoSize*sizeof(float));
	for(m=0;m<N;m++){
		for(k=m;k<N;k++){
				B[j++]=C[m + N*k];
		}
		
	}
	
	//Desplegar nuevo almacenamiento en arreglo unidimensional
	for(m=0;m<nuevoSize;m++)
		printf("%5.0f ",B[m]);
	
	printf("\n\n");
	
	/*
	for(m=0;m<N*N;m++){
		printf("%08.0f",A[m]);
		printf("%c",( (m%N)<(N-1) ) ? ' ':'\n');
		
	}
	printf("\n\n");
	
	for(m=0;m<N*N;m++){
		printf("%08.0f",B[m]);
		printf("%c",( (m%N)<(N-1) ) ? ' ':'\n');
		
	}
	printf("\n\n");
	*/
	int NN;
	NN=n;
	//for(m=0;m<NN*NN;m++){
	//int NN=16;
	for(m=0;m<NN;m++){
		for(k=0;k<NN;k++){
			printf("%05.0f",C[k + m*N]);
			printf("%c",( ((m*N+k)%NN)<(NN-1) ) ? ' ':'\n');
			//printf("%c",( (m%N)<(N-1) ) ? ' ':'\n');
		}
		
		
	}  
	printf("\n\n");
	
	float elapsedTime;
	cudaEventElapsedTime(&elapsedTime,start,stop);
	printf("Tiempo %4.6f milseg\n\n",elapsedTime);
	
	
	cudaMalloc((void**)&db, nuevoSize*sizeof(float));
	cudaMemcpy(db,B, nuevoSize*sizeof(float), cudaMemcpyHostToDevice);
	choleskyParalelo<<<1,512>>>(db,n);
	cudaMemcpy(B,db, nuevoSize*sizeof(float), cudaMemcpyDeviceToHost);
	
	printf("\n\n");
	for(m=0;m<nuevoSize;m++)
		printf("%4.4f ",B[m]);
	
	printf("\n\n");
	
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
	
	cudaFree(db);
	free(B);
	free(C);
	free(A);
	
	return 0;
}