#include <unistd.h>
#include <stdio.h>

#include <curand.h>
#include <curand_kernel.h>

#define N 1000

#define MAX 100

/* Inicializo valores iniciales*/
__global__ void init(unsigned int seed, curandState_t* states) {

  
  curand_init(seed, blockIdx.x, 0, &states[blockIdx.x]);
}

/* Pone un número aleatorio en un vector de números */
__global__ void randoms(curandState_t* states, unsigned int* numbers) {
  
  numbers[blockIdx.x] = curand(&states[blockIdx.x]) % 100000; /* este último número es el largo del número */
}

int main( ) {
  /* mandamos un state a cada thread  */
  curandState_t* states;

  cudaMalloc((void**) &states, N * sizeof(curandState_t));

  /* inicializamos todos los threads */
  init<<<N, 1>>>(time(0), states);

  unsigned int cpu_nums[N];
  unsigned int* gpu_nums;
  cudaMalloc((void**) &gpu_nums, N * sizeof(unsigned int));

  /* llamamos la función para generar números */
  randoms<<<N, 1>>>(states, gpu_nums);

  cudaMemcpy(cpu_nums, gpu_nums, N * sizeof(unsigned int), cudaMemcpyDeviceToHost);

  for (int i = 0; i < N; i++) {
    printf("%u\n", cpu_nums[i]);
  }

  cudaFree(states);
  cudaFree(gpu_nums);

  return 0;
}