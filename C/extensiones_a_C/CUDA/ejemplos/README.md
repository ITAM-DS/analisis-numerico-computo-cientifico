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

Obsérvese que en el siguiente programa se asume que `N` es menor al número máximo de bloques que se pueden lanzar en la GPU y que en caso que se eligiera `N` un valor mayor a este número máximo no se realizaría la suma de los elementos del arreglo desde la posición `N` en adelante. **Pregunta: ¿cómo se arregla esto utilizando un else?** (tip: usar un *stride* que involucre las variables `blockDim.x` y `gridDim.x` para calcular el número total de threads y modificar la variable `tid`, ver [CUDA Pro Tip: Write Flexible Kernels with Grid-Stride Loops](https://devblogs.nvidia.com/cuda-pro-tip-write-flexible-kernels-grid-stride-loops/)).

`suma_vectorial.cu`:

```
#include<stdio.h>
#define N 10
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = blockIdx.x;
	if(tid<N) //suposición N menor al número máximo de bloques que se pueden lanzar
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
	suma_vect<<<N,1>>>(device_a,device_b,device_c); //N bloques de 1 thread
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

`suma_vectorial_2.cu`:

Obsérvese que en el siguiente programa se asume que `N` es menor al número máximo de threads que se pueden lanzar en un bloque y que en caso que se eligiera `N` un valor mayor a este número máximo no se realizaría la suma de los elementos del arreglo desde la posición `N` en adelante.


```
#include<stdio.h>
#define N 10
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = threadIdx.x;
	if(tid<N) //suposición N menor al número máximo de threads en un bloque
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
	suma_vect<<<1,N>>>(device_a,device_b,device_c); //1 bloque con N threads
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
$nvcc suma_vectorial_2.cu -o suma_vectorial_2.out
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
9+81 = 90
```


Y se puede utilizar [nvprof](https://docs.nvidia.com/cuda/profiler-users-guide/index.html#nvprof-overview) para perfilamiento del programa:

```
$nvprof ./suma_vectorial.out
```

Salida:

```
==68883== NVPROF is profiling process 68883, command: ./suma_vectorial.out
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
==68883== Profiling application: ./suma_vectorial.out
==68883== Profiling result:
Time(%)      Time     Calls       Avg       Min       Max  Name
 45.82%  8.0640us         1  8.0640us  8.0640us  8.0640us  suma_vect(int*, int*, int*)
 32.18%  5.6640us         1  5.6640us  5.6640us  5.6640us  [CUDA memcpy DtoH]
 22.00%  3.8720us         2  1.9360us  1.6320us  2.2400us  [CUDA memcpy HtoD]

==68883== API calls:
Time(%)      Time     Calls       Avg       Min       Max  Name
 98.80%  70.344ms         3  23.448ms  6.0790us  70.332ms  cudaMalloc
  0.69%  490.76us         3  163.59us  31.111us  424.27us  cudaMemcpy
  0.19%  134.89us         3  44.963us  5.0180us  116.31us  cudaFree
  0.14%  101.43us        83  1.2220us      89ns  51.713us  cuDeviceGetAttribute
  0.07%  49.787us         1  49.787us  49.787us  49.787us  cudaLaunch
  0.04%  26.117us         1  26.117us  26.117us  26.117us  cudaDeviceSynchronize
  0.03%  23.240us         1  23.240us  23.240us  23.240us  cuDeviceGetName
  0.01%  8.4970us         3  2.8320us     180ns  7.2470us  cudaSetupArgument
  0.01%  7.0830us         1  7.0830us  7.0830us  7.0830us  cudaSetDeviceFlags
  0.01%  6.3870us         1  6.3870us  6.3870us  6.3870us  cuDeviceTotalMem
  0.00%  3.5340us         1  3.5340us  3.5340us  3.5340us  cudaConfigureCall
  0.00%  2.1690us         2  1.0840us     182ns  1.9870us  cuDeviceGetCount
  0.00%     295ns         2     147ns     108ns     187ns  cuDeviceGet
```


```
$nvprof ./suma_vectorial_2.out
```

Salida:

```
==68885== NVPROF is profiling process 68885, command: ./suma_vectorial_2.out
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
==68885== Profiling application: ./suma_vectorial_2.out
==68885== Profiling result:
Time(%)      Time     Calls       Avg       Min       Max  Name
 51.81%  10.080us         1  10.080us  10.080us  10.080us  suma_vect(int*, int*, int*)
 29.11%  5.6640us         1  5.6640us  5.6640us  5.6640us  [CUDA memcpy DtoH]
 19.08%  3.7120us         2  1.8560us  1.4720us  2.2400us  [CUDA memcpy HtoD]

==68885== API calls:
Time(%)      Time     Calls       Avg       Min       Max  Name
 99.08%  61.896ms         3  20.632ms  4.1740us  61.886ms  cudaMalloc
  0.46%  286.10us         3  95.367us  20.794us  237.86us  cudaMemcpy
  0.14%  87.430us         3  29.143us  4.6150us  75.873us  cudaFree
  0.13%  83.587us        83  1.0070us      88ns  34.076us  cuDeviceGetAttribute
  0.06%  37.604us         1  37.604us  37.604us  37.604us  cudaLaunch
  0.05%  29.602us         1  29.602us  29.602us  29.602us  cudaDeviceSynchronize
  0.03%  20.714us         1  20.714us  20.714us  20.714us  cuDeviceGetName
  0.02%  13.022us         3  4.3400us     213ns  12.326us  cudaSetupArgument
  0.01%  6.2560us         1  6.2560us  6.2560us  6.2560us  cuDeviceTotalMem
  0.01%  5.0080us         1  5.0080us  5.0080us  5.0080us  cudaSetDeviceFlags
  0.00%  2.3130us         1  2.3130us  2.3130us  2.3130us  cudaConfigureCall
  0.00%  2.1790us         2  1.0890us     183ns  1.9960us  cuDeviceGetCount
  0.00%     307ns         2     153ns      94ns     213ns  cuDeviceGet
```

**Obsérvese** que con la modificación siguiente se puede quitar la suposición `N` menor al número máximo de threads en un bloque: (ver [An Even Easier Introduction to CUDA](https://devblogs.nvidia.com/even-easier-introduction-cuda/))


```
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = threadIdx.x;
	int stride = blockDim.x;
	for(i=tid;i<N;i=i+stride)
		c[i] = a[i]+b[i];
}
```


## Unified memory

-> disponible para tarjetas GPU con arquitectura de SM 3.0 or más (clase Kepler o nuevas) 
ver:

* [Unified Memory in CUDA 6](https://devblogs.nvidia.com/unified-memory-in-cuda-6/)

* [Unified Memory Programming](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#um-unified-memory-programming-hd)

* [Unified Memory for CUDA Beginners](https://devblogs.nvidia.com/unified-memory-cuda-beginners/)

* [Everything you need to know about unified memory](http://on-demand.gputechconf.com/gtc/2018/presentation/s8430-everything-you-need-to-know-about-unified-memory.pdf)

Suma con `N` bloques con 1 thread:

`suma_vectorial_unified_memory.cu`:

```
#include<stdio.h>
#define N 10
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = blockIdx.x;
	if(tid<N) #suposición N menor al número máximo de bloques que se pueden lanzar
		c[tid] = a[tid]+b[tid];
}
int main(void){
	int *device_a, *device_b, *device_c;
	int i;
	cudaMallocManaged(&device_a, N*sizeof(double));
	cudaMallocManaged(&device_b, N*sizeof(double));
	cudaMallocManaged(&device_c, N*sizeof(double));

	//inicializando los arreglos en el host:
	for(i=0;i<N;i++){
		device_a[i]=i;
		device_b[i]=i*i;
	}

	//mandamos a llamar a suma_vect:
    cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	suma_vect<<<N,1>>>(device_a,device_b,device_c); //N bloques de 1 thread

	//esperar a que la GPU finalice los cálculos
    cudaDeviceSynchronize();

	for(i=0;i<N;i++)
		printf("%d+%d = %d\n",device_a[i],device_b[i],device_c[i]);
	cudaFree(device_a);
	cudaFree(device_b);
	cudaFree(device_c);
	return 0;
}

```

Compilamos:

```
$nvcc suma_vectorial_unified_memory.cu -o suma_vectorial_unified_memory.out
```


Ejecutamos:


```
$./suma_vectorial_unified_memory.out
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



Suma con 1 bloques con `N` threads:

`suma_vectorial_unified_memory_2.cu`:

```
#include<stdio.h>
#define N 10
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = threadIdx.x; #suposición N menor al número máximo de threads en un bloque
	if(tid<N)
		c[tid] = a[tid]+b[tid];
}
int main(void){
	int *device_a, *device_b, *device_c;
	int i;
	cudaMallocManaged(&device_a, N*sizeof(double));
	cudaMallocManaged(&device_b, N*sizeof(double));
	cudaMallocManaged(&device_c, N*sizeof(double));

	//inicializando los arreglos en el host:
	for(i=0;i<N;i++){
		device_a[i]=i;
		device_b[i]=i*i;
	}

	//mandamos a llamar a suma_vect:
    cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	suma_vect<<<1,N>>>(device_a,device_b,device_c); //1 bloque de N threads

	//esperar a que la GPU finalice los cálculos
    cudaDeviceSynchronize();

	for(i=0;i<N;i++)
		printf("%d+%d = %d\n",device_a[i],device_b[i],device_c[i]);
	cudaFree(device_a);
	cudaFree(device_b);
	cudaFree(device_c);
	return 0;
}
```

Compilamos:

```
$nvcc suma_vectorial_unified_memory_2.cu -o suma_vectorial_unified_memory_2.out
```


Ejecutamos:


```
$./suma_vectorial_unified_memory_2.out
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
