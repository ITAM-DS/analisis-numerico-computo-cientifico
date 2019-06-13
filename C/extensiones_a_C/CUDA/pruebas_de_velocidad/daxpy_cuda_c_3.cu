//nvcc --compiler-options -Wall daxpy_cuda_c_3.cu funciones.c -o daxpy_cuda_c_3.out
// ./daxpy_cuda_c_3.out <dimension de vectores> <número de threads>

#include<stdio.h>

__global__ void daxpy(double *a, double *b, double *alpha, int *N){
	int tid = blockIdx.x*blockDim.x+threadIdx.x;
	int stride = blockDim.x*gridDim.x;
	int i;
		for(i=tid;i<*N;i+=stride)
			b[i] = b[i] + (*alpha)*a[i];

}


int main(int argc, char *argv[]){
	double *a, *b;
	double *device_a, *device_b;
	int i;
	double al=3.5;
	double *d_al;
	int N;
	int num_threads;
	int numSMs;
	int *d_N;
	double time_spent;

	//dimensiones
	N=atoi(argv[1]);

	num_threads=atoi(argv[2]);
	//alojando en host:
	a = (double *)calloc(N,sizeof(double));
	b = (double *)calloc(N,sizeof(double));

	//alojando en device
	cudaMalloc((void **)&device_a, sizeof(double)*N);
	cudaMalloc((void **)&device_b, sizeof(double)*N);
	cudaMalloc((void **)&d_al, sizeof(double));
	cudaMalloc((void **)&d_N, sizeof(int));
	//llenando los arreglos:
	for(i=0;i<N;i++){
		a[i]=i;
		b[i]=i*i;
	}
	//copiamos arreglos a, b a la GPU
	cudaMemcpy(device_a,a,N*sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(device_b,b,N*sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(d_al,&al,sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(d_N,&N,sizeof(int), cudaMemcpyHostToDevice);

	//número de SM's
	cudaDeviceGetAttribute(&numSMs, cudaDevAttrMultiProcessorCount, 0);
	//mandamos a llamar a daxpy:
    cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	clock_t begin = clock();
	daxpy<<<32*numSMs,num_threads>>>(device_a,device_b,d_al,d_N); //N bloques de 1 thread
    cudaDeviceSynchronize();
    clock_t end = clock();
    //tiempo de cálculo:
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo de cálculo en la gpu %.5f\n", time_spent);
	//copia del resultado al arreglo b:
	cudaMemcpy(b,device_b,N*sizeof(double),cudaMemcpyDeviceToHost);
	
	cudaFree(device_a);
	cudaFree(device_b);
	cudaFree(d_al);
	cudaFree(d_N);
	return 0;
}




