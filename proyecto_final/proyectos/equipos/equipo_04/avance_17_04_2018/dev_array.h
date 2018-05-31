/************************************************************************************************/
/************ Arturo Gonzalez Bencomo 172906, Arturo Torre Gonzalez 90226 ***********************/
/************************************************************************************************/
/********************************** dev_array.h *************************************************/
/************************************************************************************************/
/** En este archivo se especifica la estructura de datos dev_array auxiliar *********************/

/*Directivas del preprocesador de C*/
#ifndef _DEV_ARRAY_H_
#define _DEV_ARRAY_H_

/* Cargamos librerias*/
#include <stdexcept>
#include <algorithm>
#include <cuda_runtime.h>

/*Especificacion de un objeto llamado dev_array*/ 
template <class T>
class dev_array
{
// public functions
public:
    explicit dev_array()
        : start_(0),
          end_(0)
    {}

    // constructor
    explicit dev_array(size_t size)
    {
        allocate(size);
    }
    // destructor
    ~dev_array()
    {
        free();
    }

    // resize the vector
    void resize(size_t size)
    {
        free();
        allocate(size);
    }

    // get the size of the array
    size_t getSize() const
    {
        return end_ - start_;
    }

    // get data
    const T* getData() const
    {
        return start_;
    }

    T* getData()
    {
        return start_;
    }

    // set
    void set(const T* src, size_t size)
    {
        size_t min = std::min(size, getSize());
        cudaError_t result = cudaMemcpy(start_, src, min * sizeof(T), cudaMemcpyHostToDevice);
        if (result != cudaSuccess)
        {
            throw std::runtime_error("failed to copy to device memory");
        }
    }
    // get
    void get(T* dest, size_t size)
    {
        size_t min = std::min(size, getSize());
        cudaError_t result = cudaMemcpy(dest, start_, min * sizeof(T), cudaMemcpyDeviceToHost);
        if (result != cudaSuccess)
        {
            throw std::runtime_error("failed to copy to host memory");
        }
    }


// Metodos privados
private:
    // Asignar memoria en el device
    void allocate(size_t size)
    {
        cudaError_t result = cudaMalloc((void**)&start_, size * sizeof(T));
        if (result != cudaSuccess)
        {
            start_ = end_ = 0;
            throw std::runtime_error("failed to allocate device memory");
        }
        end_ = start_ + size;
    }

    // Liberar meemoria en el device
    void free()
    {
        if (start_ != 0)
        {
            cudaFree(start_);
            start_ = end_ = 0;
        }
    }

    T* start_;
    T* end_;
};

#endif
