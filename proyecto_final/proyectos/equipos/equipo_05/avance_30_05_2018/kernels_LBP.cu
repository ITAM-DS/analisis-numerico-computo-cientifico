#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <iostream>
#include <vector>

//includes de CUDA 
#include <cuda.h>
#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <helper_functions.h>
#include "device_functions.h"

//Clases necesarias
#include "BinaryRestriction.h"
#include "VectorBR.h"
#include "BinaryMixer.h"

//__device__ int cont = 0;
int block_width = 1024;



#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort = true)
{
	if (code != cudaSuccess)
	{
		fprintf(stderr, "GPUassert: \"%s\": %s %s %d\n", cudaGetErrorName(code), cudaGetErrorString(code), file, line);
		if (abort) exit(code);
	}
}

//funcion que me regrese el contador

__global__ void ParallelMix(unsigned long long int * d_cont ,unsigned int number_threads, int d_rest_size ,int numStations, unsigned int * d_temp, unsigned int * d_rest, unsigned int * d_out) {

	//ID del thread
	const unsigned int tid = blockIdx.x * blockDim.x + threadIdx.x;

	//Condition that verifies the usefulness of the thread.
	if (tid < number_threads) {

		//VARIABLES

		//Esta variable auxiliar denota la doble asignación de una actividad si es >0.  
		unsigned int aux_v = 0;

		//Esta otra variable denota que actividades se hana asignado.
		unsigned int cum_v = 0;

		//Bandera que se dispara si una actividade se ha asigando dos veces.
		bool flag = false;

		//Este vector auxiliar es una cota, segun el enumero de estaciones de un problema.
		//Por el momento dejarlo en 7. (revisar despues con el doc)
		unsigned int aux[7] = { 0,0,0,0,0,0,0 };

		//Imprimimos el thread
		//printf("Thread Num: %d \n", number_threads);
		//printf("Thread ID: %d \n", tid);

		//for donde se itern sobre todas las tablas de solución en Ri.
		//Cada thread intersectará cada tabla de solución en la nueva restriccion d_temp.
		for (int i = 0; i <d_rest_size ; i++) {

			//Perform OR operations on every line (STATION) of the solution table.
			//Se hace un or en cada linea (osea cad estación) de la tabla de solución.

			//Esto para identificar si una actividad esta asignada a más de una estación.
			for (int k = 0; k<numStations; k++) {

				// El pseudo código del algoritmo de intersección booleana es el siguiente.
				//1. Perform OR operation on table row (k) from tid solution table (d_temp) and new constraint (d_rest).
				//1. Primero haz un or sobre la fila k (osea estación) de la tabla de solución d_temp y la nueva restriccioń d_rest.
				//	 Se guarda el resultado en aux[k].cx, que declaramos arriba.
				//		1.1. Realizar operación AND con aux[k] y cum_v. 
				///////////////////////////////////////////////////////////////////////////////

				aux[k] = *(d_temp + (tid*numStations + k)) | *(d_rest + k + (i*numStations));


				//actualización de vector aux con el AND siempre y cuando la bandera no se
				//haya disparado.
				if (!flag) {
					aux_v = cum_v & aux[k];
					if (aux_v > 0) {
						flag = true;
					}
					cum_v = cum_v^aux[k];
				}
			}

			if (!flag) {
				//Tabla VALIDA
				aux_v = atomicAdd(d_cont, 1);
				
				for (int j = 0; j < numStations; j++) {
					*(d_out + (aux_v*numStations) + j) = aux[j];
					
				}
				printf("VALIDA %d, %d\n", tid, i);
				flag = false;
				aux_v = 0;
				cum_v = 0;

			}
			else {
				//Tabla INVALIDA
				printf("INVALIDA %d, %d\n", tid, i);
				flag = false;
				aux_v = 0;
				cum_v = 0;

			}
		}
		//Termina forloop
		//free memory from the variables

	}
}

extern "C" bool
runTest(int argc, const char **argv, unsigned long long int * h_cont, int numStations, unsigned int * h_temp, unsigned long long int h_temp_size , unsigned int * h_rest, int h_rest_size, unsigned int * h_out) {

	//use command-line specified CUDA device, otherwise use device with highest Gflops
	//esta linea tal vez no sea necesaria, al fin sólo tomará la GPU del servidor.
	findCudaDevice(argc, (const char **)argv);

	//Calcula los threads y los bloques.
	unsigned int num_threads = h_temp_size / numStations;
	unsigned int num_blocks = 1 + (num_threads / block_width);
	
	cout << "Number of threads: " << num_threads << endl;
	cout << "Number of Blocks:  " << num_blocks << endl;

	//GPU memory status variables
	size_t total_mem, free_mem;

	//Memory requirement for restriction
	const size_t mem_size_rest = sizeof(int) * h_rest_size;

	//Create Device Variables
	unsigned int * d_rest;
	unsigned int * d_out;
	unsigned long long int * d_cont;
	unsigned long long int * internal_cont = new unsigned long long int[1];
	*(internal_cont) = 0;


	//Se hacen las reservas de memoria en la gpu.
	checkCudaErrors(cudaMalloc((void **)&d_rest, mem_size_rest));
	checkCudaErrors(cudaMalloc((void **)&d_cont, sizeof(unsigned long long int)));

	//se copia de lamemoria el host al device.
	checkCudaErrors(cudaMemcpy(d_rest, h_rest, mem_size_rest, cudaMemcpyHostToDevice));
	
	gpuErrchk(cudaMemcpy(d_cont, h_cont, sizeof(unsigned long long int), cudaMemcpyHostToDevice));

	//reporte de la memoria.
	cudaMemGetInfo(&free_mem, &total_mem);
	printf("Free Memory: %s \tTotal Memory: %s \n", to_string(free_mem), to_string(total_mem));

	
	//cout << "Out vector byte size: " << to_string(mem_size_out) << endl;
	//cout << "Rest vector size: " << h_rest_size << endl;
	//printf("Out vector size: %s\n", to_string((h_temp_size * (h_rest_size / numStations))));
	

	//Declare a 1 MB constant
	const size_t MB = 1 << 20;

	//Buffer Conffiguration: Servirá para administrar los batches en la GPU.
	cudaError_t status;
	unsigned int * buffer;

	//Allocate at mmost 500MB of memory for the buffer size.
	//This limitation will allow us to allocate enough memory to store the resulting solutions vector.
	size_t buffer_size = std::min((long long)4294967296 / (h_rest_size / numStations), (long long)536870912);
        //Make sure the allocation is succesful
	for (; buffer_size > MB; buffer_size -= MB) {
		//Allocate memory for buffer
		status = cudaMalloc((void **)&buffer, buffer_size);
		if (status == cudaSuccess)
			break;
	}

	//Bytes reservados en la GPU
	cout << "Allocated " << buffer_size << " bytes on GPU. " << endl;
	cout << h_temp_size << " int items require processing. " << endl;
	//PRINT: Batch size.

	
	//Tamaño del buffer auxiliar, ayua a preservar la integridad del vector de soluciones.
	size_t aux_buff_size = (buffer_size / sizeof(int)) % numStations;

	//Numero de elementos enteros que serán procesados en este batch.
	size_t batchN = (buffer_size - aux_buff_size) / sizeof(int);

	//elementos a la espera de procesarse.
	size_t remainN = h_temp_size;

	
	int elements_out = batchN * (h_rest_size / numStations);
	const size_t mem_size_out = elements_out * sizeof(int);
	checkCudaErrors(cudaMalloc((void **)&d_out, mem_size_out));

	cout << "Number of int proccessed in this batch: " << batchN << endl;


	//Loop sobre los datos del host, en batches prdefinidos arriba.
	for (; remainN > 0; remainN -= batchN) {

		cout << "\n BATCH \n\n";

		//Si remain es menor que el tamano del batch,
		//ajusto el tamano del batch a lo que queda de datos
		//y en caso contrario lo dejo igual
		batchN = (remainN<batchN) ? remainN : batchN;
		size_t worksize = batchN * sizeof(int);
		cout << "Processing " << batchN << "/" << remainN << " items remaining." << endl;

		//COPY values from host temporal solution to buffer.
		//Process the items in buffer.
		cudaMemcpy(buffer, h_temp, worksize, cudaMemcpyHostToDevice);

		//La cantidad de threads se determina por el número de tablas de solucion en el vector.
		num_threads = batchN / numStations;
		num_blocks = 1 + (num_threads / block_width);
		//Prints
		cout << "Number of threads: " << num_threads << endl;
		cout << "Number of Blocks:  " << num_blocks << endl;

		

		//Lanzamos el kernel.
		ParallelMix << < num_blocks, block_width >> >(d_cont, num_threads, h_rest_size / numStations, numStations, buffer, d_rest, d_out);


		cout << "Succesful execution\n";

		//copiamos el contador de tablas de lgpu al cpu.
		gpuErrchk(cudaMemcpy(h_cont, d_cont, sizeof(unsigned long long int), cudaMemcpyDeviceToHost));

		*(internal_cont) += *(h_cont);
		cout << "Succesful execution\n";
		//Se copin las soluciones validas al host.
		//d_cont es el numero de soluciones de tablas válidas  a partir ed que se corrió el kernel.
		
		cout << *(h_cont) << endl;
		cout << "ACUM: " << *(internal_cont) << endl;

		gpuErrchk(cudaMemcpy(h_out, d_out,*(h_cont)*numStations*sizeof(int), cudaMemcpyDeviceToHost));
		
		//Se actualizan apuntadores en la magnitud del batch que se procesó.
		h_temp += batchN;
		//Se actualiza el apuntado h_put en la magnitud del numero de soluciones validas del batch procesado.
		h_out = h_out + (*(h_cont)*numStations);

		gpuErrchk(cudaMemset(d_cont, (unsigned long long int)0, sizeof(unsigned long long int)));
		gpuErrchk(cudaMemset(d_out, 0,mem_size_out));
	}

	

	//GPU memory status REPORT.
	cudaMemGetInfo(&free_mem, &total_mem);
	printf("Free Memory: %s \tTotal Memory: %s \n", to_string(free_mem), to_string(total_mem));

	*(h_cont) = *(internal_cont);


	//cleanup device memory

	//Reset Device
	cudaDeviceReset();

	return 0;


}
