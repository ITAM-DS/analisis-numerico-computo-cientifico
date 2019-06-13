//nvcc --compiler-options -Wall daxpy_cuda_c_1.cu funciones.c -o daxpy_cuda_c_1.out
// ./daxpy_cuda_c_1.out <dimension de vectores>

#include<stdio.h>

__global__ void daxpy(double *a, double *b, double *alpha, int *N){
	int tid = blockIdx.x;
		if(tid<*N)
			b[tid] = b[tid] + (*alpha)*a[tid];

}


int main(int argc, char *argv[]){
	double *a, *b;
	double *device_a, *device_b;
	int i;
	double al=3.5;
	double *d_al;
	int N;
	int *d_N;
	double time_spent;

	//dimensiones
	N=atoi(argv[1]);

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
	//mandamos a llamar a daxpy:
        cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);

	clock_t begin = clock();
	daxpy<<<N,1>>>(device_a,device_b,d_al,d_N); //N bloques de 1 thread
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




