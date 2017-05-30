/*Autores: 
*Walter Martínez Santana 
*José Carlos Castro
*/

#include <stdio.h>

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

#define n 300
#define SIZE n*n*sizeof(float)

int main(){

	int N=n;
	float *A, *B, *C;
	float *da, *db, *dc;
	int m;
	
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);	
	dim3 dimGrid(16, 16);
	dim3 dimBlock(16, 16);
	
	A=(float *)malloc(SIZE);
	B=(float *)malloc(SIZE);
	C=(float *)malloc(SIZE);
	for(m=0;m<N*N;m++){
		A[m]=(float)1;
		B[m]=(float)1;
		C[m]=(float)0;
	}
	
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
	
	
	
	for(m=0;m<N*N;m++){
		printf("%08.0f",A[m]);
		printf("%c",( (m%N)<(N-1) ) ? '\t':'\n');
		
	}
	printf("\n\n");
	
	for(m=0;m<N*N;m++){
		printf("%08.0f",B[m]);
		printf("%c",( (m%N)<(N-1) ) ? '\t':'\n');
		
	}
	printf("\n\n");
	
	for(m=0;m<N*N;m++){
		printf("%08.0f",C[m]);
		printf("%c",( (m%N)<(N-1) ) ? '\t':'\n');
		
	} 
	printf("\n\n");
	
	float elapsedTime;
	cudaEventElapsedTime(&elapsedTime,start,stop);
	printf("Tiempo %4.6f milseg\n\n",elapsedTime);
	
	
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
	
	cudaFree(da);
	cudaFree(db);
	cudaFree(dc);
	free(A);
	free(B);
	free(C);
	
	return 0;
}
