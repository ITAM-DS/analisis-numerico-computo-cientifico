# Ejemplos

Se asume que se ha levantado una instancia en Amazon Web Services utilizando las indicaciones de [aquí](/C/extensiones_a_C/CUDA/instalacion/).

Se utilizará una instancia tipo `p2.xlarge` de AWS.


## Información del device:


Para obtener información del device seguimos las instrucciones de la sección [Running the Binaries](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html#running-binaries):

```
cd /usr/local/cuda/samples/1_Utilities/deviceQuery && sudo make all Makefile && cd

```

Ejecutamos:

```
/usr/local/cuda/samples/1_Utilities/deviceQuery/deviceQuery

```

Resultado:

```
/usr/local/cuda/samples/1_Utilities/deviceQuery/deviceQuery Starting...

 CUDA Device Query (Runtime API) version (CUDART static linking)


Detected 1 CUDA Capable device(s)

Device 0: "Tesla K80"
  CUDA Driver Version / Runtime Version          9.1 / 9.1
  CUDA Capability Major/Minor version number:    3.7
  Total amount of global memory:                 11441 MBytes (11996954624 bytes)
  (13) Multiprocessors, (192) CUDA Cores/MP:     2496 CUDA Cores
  GPU Max Clock rate:                            824 MHz (0.82 GHz)
  Memory Clock rate:                             2505 Mhz
  Memory Bus Width:                              384-bit
  L2 Cache Size:                                 1572864 bytes
  Maximum Texture Dimension Size (x,y,z)         1D=(65536), 2D=(65536, 65536), 3D=(4096, 4096, 4096)
  Maximum Layered 1D Texture Size, (num) layers  1D=(16384), 2048 layers
  Maximum Layered 2D Texture Size, (num) layers  2D=(16384, 16384), 2048 layers
  Total amount of constant memory:               65536 bytes
  Total amount of shared memory per block:       49152 bytes
  Total number of registers available per block: 65536
  Warp size:                                     32
  Maximum number of threads per multiprocessor:  2048
  Maximum number of threads per block:           1024
  Max dimension size of a thread block (x,y,z): (1024, 1024, 64)
  Max dimension size of a grid size    (x,y,z): (2147483647, 65535, 65535)
  Maximum memory pitch:                          2147483647 bytes
  Texture alignment:                             512 bytes
  Concurrent copy and kernel execution:          Yes with 2 copy engine(s)
  Run time limit on kernels:                     No
  Integrated GPU sharing Host Memory:            No
  Support host page-locked memory mapping:       Yes
  Alignment requirement for Surfaces:            Yes
  Device has ECC support:                        Enabled
  Device supports Unified Addressing (UVA):      Yes
  Supports Cooperative Kernel Launch:            No
  Supports MultiDevice Co-op Kernel Launch:      No
  Device PCI Domain ID / Bus ID / location ID:   0 / 0 / 30
  Compute Mode:
     < Default (multiple host threads can use ::cudaSetDevice() with device simultaneously) >

deviceQuery, CUDA Driver = CUDART, CUDA Driver Version = 9.1, CUDA Runtime Version = 9.1, NumDevs = 1
Result = PASS
```

Para descripciones de los siguientes puntos dar click:

* [Compute capability](http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#compute-capabilities) devices con compute capability >=1.3 soportan single y double precision.

* [Propiedades del device](http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__DEVICE.html#group__CUDART__DEVICE_1g1bf9d625a931d657e08db2b4391170f0)



## Información del NVIDIA driver:


```
$nvidia-smi
```
**(smi: system management interface)**

Salida:

```
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 390.30                 Driver Version: 390.30                    |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|===============================+======================+======================|
|   0  Tesla K80           Off  | 00000000:00:1E.0 Off |                    0 |
| N/A   41C    P0    73W / 149W |      0MiB / 11441MiB |     99%      Default |
+-------------------------------+----------------------+----------------------+

+-----------------------------------------------------------------------------+
| Processes:                                                       GPU Memory |
|  GPU       PID   Type   Process name                             Usage      |
|=============================================================================|
|  No running processes found                                                 |
+-----------------------------------------------------------------------------+

```



## Programa de hello world:

`hello_world.cu`:

```
#include<stdio.h>
__global__ void func(void){
	
}
int main(void){
	func<<<1,1>>>();
	printf("Hello world!\n");
	return 0;
}
```

Compilamos:

```
$nvcc hello_world.cu -o hello_world.out
```

Ejecutamos:

```
$./hello_world.out
```

## Programa hello world 2:

Usamos la función `cudaDeviceSynchronize` para que el CPU-thread espere hasta que el device haya completado todos los tasks previos.

`hello_world_2.cu`

```
#include<stdio.h>
__global__ void func(void){
	printf("Hello world del bloque %d del thread %d!\n", blockIdx.x, threadIdx.x);
}
int main(void){
	func<<<3,3>>>(); //3 bloques de 3 threads cada uno
	cudaDeviceSynchronize();
	printf("Hola del cpu thread\n");
	return 0;
}

```

Compilamos:

```
$nvcc hello_world_2.cu -o hello_world_2.out
```

Ejecutamos:

```
$./hello_world_2.out
```

Salida:

```
Hello world del bloque 1 del thread 0!
Hello world del bloque 1 del thread 1!
Hello world del bloque 1 del thread 2!
Hello world del bloque 0 del thread 0!
Hello world del bloque 0 del thread 1!
Hello world del bloque 0 del thread 2!
Hello world del bloque 2 del thread 0!
Hello world del bloque 2 del thread 1!
Hello world del bloque 2 del thread 2!
Hola del cpu thread

```

En la [documentación](http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__DEVICE.html#group__CUDART__DEVICE_1g10e20b05a95f638a4071a655503df25d) de la función `cudaDeviceSynchronize` se menciona que para que el cpu-thread espere teniendo un 0% de uso hay que definir una flag llamada `cudaDeviceScheduleBlockingSync` (en el ejemplo anterior el cpu-thread realiza un busy-waiting):


```
#include<stdio.h>
__global__ void func(void){
	printf("Hello world del bloque %d del thread %d!\n", blockIdx.x, threadIdx.x);
}
int main(void){
	cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	func<<<3,3>>>();
	cudaDeviceSynchronize();
	printf("Hola del cpu thread\n");
	return 0;
}

```


## Programa de suma:

`suma.cu`:

```
#include<stdio.h>
__global__ void suma(int a, int b, int *c){
	*c = a+b;
}
int main(void){
	int c;
	int *device_c;
	cudaMalloc((void **)&device_c,sizeof(int));
        cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	suma<<<1,1>>>(2,7,device_c);
        cudaDeviceSynchronize();
	cudaMemcpy(&c, device_c, sizeof(int), cudaMemcpyDeviceToHost);
	printf("2+7 = %d\n", c);
	cudaFree(device_c);
	return 0;
}

```

Compilamos:

```
$nvcc suma.cu -o suma.out
```

Ejecutamos:

```
$./suma.out
```

Salida:

```
2+7 = 9
```

## Programa de suma vectorial:

Lanzamos `N` bloques de 1 thread que ejecuten el kernel.


`suma_vectorial.cu`:

```
#include<stdio.h>
#define N 10
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = blockIdx.x;
	if(tid<N)
		c[tid] = a[tid]+b[tid];
}
int main(void){
	int a[N], b[N],c[N];
	int *device_a, *device_b, *device_c;
	int i;
	//alojando en device
	cudaMalloc((void **)&device_a, sizeof(int)*N);
	cudaMalloc((void **)&device_b, sizeof(int)*N);
	cudaMalloc((void **)&device_c, sizeof(int)*N);
	//llenando los arreglos:
	for(i=0;i<N;i++){
		a[i]=i;
		b[i]=i*i;
	}
	//copiamos arreglos a, b a la GPU
	cudaMemcpy(device_a,a,N*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_b,b,N*sizeof(int), cudaMemcpyHostToDevice);
	//mandamos a llamar a suma_vect:
        cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	suma_vect<<<N,1>>>(device_a,device_b,device_c);
        cudaDeviceSynchronize();
	//copia del resultado al arreglo c:
	cudaMemcpy(c,device_c,N*sizeof(int),cudaMemcpyDeviceToHost);
	for(i=0;i<N;i++)
		printf("%d+%d = %d\n",a[i],b[i],c[i]);
	cudaFree(device_a);
	cudaFree(device_b);
	cudaFree(device_c);
	return 0;
}
```

Compilamos:

```
$nvcc suma_vectorial.cu -o suma_vectorial.out

```


Ejecutamos:


```
$./suma_vectorial.out
```

Salida:

```
0+0 = 0
1+1 = 2
2+4 = 6
3+9 = 12
4+16 = 20
5+25 = 30
6+36 = 42
7+49 = 56
8+64 = 72
9+81 = 90
```

Suma con 1 bloque con `N` threads:

``suma_vectorial_2.cu`:

```
#define N 10
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = threadIdx.x;
	if(tid<N)
		c[tid] = a[tid]+b[tid];
}
int main(void){
	int a[N], b[N],c[N];
	int *device_a, *device_b, *device_c;
	int i;
	//alojando en device
	cudaMalloc((void **)&device_a, sizeof(int)*N);
	cudaMalloc((void **)&device_b, sizeof(int)*N);
	cudaMalloc((void **)&device_c, sizeof(int)*N);
	//llenando los arreglos:
	for(i=0;i<N;i++){
		a[i]=i;
		b[i]=i*i;
	}
	//copiamos arreglos a, b a la GPU
	cudaMemcpy(device_a,a,N*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_b,b,N*sizeof(int), cudaMemcpyHostToDevice);
	//mandamos a llamar a suma_vect:
        cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	suma_vect<<<1,N>>>(device_a,device_b,device_c);
	cudaDeviceSynchronize();
	//copia del resultado al arreglo c:
	cudaMemcpy(c,device_c,N*sizeof(int),cudaMemcpyDeviceToHost);
	for(i=0;i<N;i++)
		printf("%d+%d = %d\n",a[i],b[i],c[i]);
	cudaFree(device_a);
	cudaFree(device_b);
	cudaFree(device_c);
	return 0;
}

```

Compilamos:

```
$nvcc suma_vectorial_2.cu -o suma_vectorial.out

```


Ejecutamos:


```
$./suma_vectorial_2.out
```

Salida:

```
0+0 = 0
1+1 = 2
2+4 = 6
3+9 = 12
4+16 = 20
5+25 = 30
6+36 = 42
7+49 = 56
8+64 = 72
```

Y se puede utilizar [nvprof](https://docs.nvidia.com/cuda/profiler-users-guide/index.html#nvprof-overview) para perfilamiento del programa:

```
$nvprof ./suma_vectorial.out
```
