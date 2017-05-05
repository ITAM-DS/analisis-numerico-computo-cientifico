# Avance_02_05_2017

## Integrantes:

* Ricardo Lastra

* Adrián Vázquez

## Trabajo:

### Individual

Adrián Vázquez (120028):


__Implementación de arquitectura__

Se determino que se usara [MPI](mpi.md) para  la distribucion inicial de tareas "Chunk" usando computo en paralelo. Este cluster es una propuesta final.

____


Ricardo Lastra (160167):

__Metodo para calculo de SVD__

Se desarrollo la Fase 2 del metodo thin segun las notas de clase [3.2.2 Factorizaciones matriciales: SVD, Cholesky, QR.](https://www.dropbox.com/sh/azwz5p69bnbamtw/AAB5t2SafFK_1XvthNT9Tflda?dl=0)

En el avance de esta semana detalla la [Fase 2 en el siguiente documento "SVD_DE_B.html"](https://drive.google.com/drive/folders/0B5eQQH_TPIY-YjVmSE5NS3BSYzQ) la cual consta de aplicar el metodo SVD a la matriz Bidiagonal (o tridiagonal en su caso). Para ello consultamos el capitulo 10 "Large Sparse Eigenvalue Problems" del libro `Matrix Computations` de H. Golub y F. Van Loan


### Equipo
Definimos que para darle el enfoque de una arquitectura Hibrida con computo en paralelo es necesario utilizar MPI.
Tambien revisando el metodo de factorizacion SVD en su version thin, se ha desarrollado en estos dias una serie de calculos en `Rstudio` y `Python` para comprender como llegar a traves de los calculos de matrices, de una matriz original A, a una matriz Diagonal, Bidiagonal o Tridiagonal.
Para la proxima semana, se intentara tener toda la teoria del metodo thin, para asi identificar el metodo que usa CUDA en la version que estamos usando para nuestro proyecto. 
Hemos tenido un buen avance en la comprension del algoritmo, sin embargo la arquitectura y configuracion de la misma nos ha demorado mucho tiempo por complejidad de `Docker`.


## Comentarios sobre avance:

## (Respuestas) Comentarios sobre avance:
