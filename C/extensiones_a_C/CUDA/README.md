#Instalación 


## Mac OS X

Para usar CUDA es necesario que sus máquinas tengan un GPU de NVIDIA.

En esta [página](http://docs.nvidia.com/cuda/cuda-getting-started-guide-for-mac-os-x/) encuentran documentación para usar CUDA en Mac OS X.

Una vez instalado:

* El device driver de NVIDIA.

* Toolkit para desarrollo.

* Compilador estándar de C, por ejemplo `gcc`.

Pueden hacer en sus sistemas: (ejemplo para CUDA-7.5)

```
export PATH=/Developer/NVIDIA/CUDA-7.5/bin:$PATH
export DYLD_LIBRARY_PATH=/Developer/NVIDIA/CUDA-7.5/lib:$DYLD_LIBRARY_PATH
```

y revisar que su tarjeta gráfica es CUDA-enabled con:

```
$nvcc -V
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2015 NVIDIA Corporation
Built on Thu_Sep_24_00:26:39_CDT_2015
Cuda compilation tools, release 7.5, V7.5.19
```

## Ubuntu:



## AWS:



## Docker:





