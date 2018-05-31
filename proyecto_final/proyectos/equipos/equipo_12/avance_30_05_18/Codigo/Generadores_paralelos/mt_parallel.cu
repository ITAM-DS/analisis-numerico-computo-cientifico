
#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <curand_kernel.h>
#include <curand_mtgp32_host.h>
#include <curand_mtgp32dc_p_11213.h>


#define CUDA_CALL(x) do { if((x) != cudaSuccess) { \
    printf("Error at %s:%d\n",__FILE__,__LINE__); \
    return EXIT_FAILURE;}} while(0)

#define CURAND_CALL(x) do { if((x) != CURAND_STATUS_SUCCESS) { \
    printf("Error at %s:%d\n",__FILE__,__LINE__); \
    return EXIT_FAILURE;}} while(0)

__global__ void generate_kernel(curandStateMtgp32 *state, 
                                int n,
                                int *result)
{
    int id = threadIdx.x + blockIdx.x * 256;
    int count = 0;
    unsigned int x;
    for(int i = 0; i < n; i++) {
        x = curand(&state[blockIdx.x]);
        if(x & 1) {
            count++;
        }
    }

    result[id] += count;
}

int main(int argc, char *argv[])
{
    int i;
    long long total;
    curandStateMtgp32 *devMTGPStates;
    mtgp32_kernel_params *devKernelParams;
    int *devResults, *hostResults;
    int sampleCount = 10000;
    
   
    if (argc == 2) {
        sscanf(argv[1],"%d",&sampleCount);
    }
        

    hostResults = (int *)calloc(64 * 256, sizeof(int));

  
    CUDA_CALL(cudaMalloc((void **)&devResults, 64 * 256 * 
              sizeof(int)));

  
    CUDA_CALL(cudaMemset(devResults, 0, 64 * 256 * 
              sizeof(int)));

  
    CUDA_CALL(cudaMalloc((void **)&devMTGPStates, 64 * 
              sizeof(curandStateMtgp32)));
    
 
    CUDA_CALL(cudaMalloc((void**)&devKernelParams, sizeof(mtgp32_kernel_params)));
    
   
    /* copia de parametros a memoria del device              */
    CURAND_CALL(curandMakeMTGP32Constants(mtgp32dc_params_fast_11213, devKernelParams));
    
    /* Inicualiza thread blocls */
    CURAND_CALL(curandMakeMTGP32KernelState(devMTGPStates, 
                mtgp32dc_params_fast_11213, devKernelParams, 64, 1234)); 
 
    
    for(i = 0; i < 10; i++) {
        generate_kernel<<<64, 256>>>(devMTGPStates, sampleCount, devResults);
    }

    /* copia al host */
    CUDA_CALL(cudaMemcpy(hostResults, devResults, 64 * 256 * 
        sizeof(int), cudaMemcpyDeviceToHost));

    /* Show result */
    total = 0;
    for(i = 0; i < 1000; i++) {

        total += hostResults[i];
        printf("%u\n", hostResults[i]);
    }

   
    

    /* Cleanup */
    CUDA_CALL(cudaFree(devMTGPStates));
    CUDA_CALL(cudaFree(devResults));
    free(hostResults);
    printf("^^^^ kernel_mtgp_example PASSED\n");
    return EXIT_SUCCESS;
}