# daxpy

```
nvcc --compiler-options -Wall daxpy_cublas.c funciones.c -o daxpy_cublas.out -lcublas
./daxpy_cublas.out <dimensión de vectores>

nvcc --compiler-options -Wall daxpy_cuda_c_1.cu funciones.c -o daxpy_cuda_c_1.out
./daxpy_cuda_c_1.out <dimensión de vectores>

nvcc --compiler-options -Wall daxpy_cuda_c_2.cu funciones.c -o daxpy_cuda_c_2.out
./daxpy_cuda_c_2.out <dimensión de vectores>

nvcc --compiler-options -Wall daxpy_cuda_c_3.cu funciones.c -o daxpy_cuda_c_3.out
./daxpy_cuda_c_3.out <dimensión de vectores> <número de threads>

nvcc --compiler-options -Wall daxpy_cuda_c_secuencial.cu funciones.c -o daxpy_cuda_c_secuencial.out
./daxpy_cuda_c_secuencial.out <dimensión de vectores>

gcc -Wall daxpy.c funciones.c -o daxpy.out -lblas
./daxpy.out <dimensión de vectores>

```
