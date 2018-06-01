
# Paths where MAGMA, CUDA, and OpenBLAS are installed.
# MAGMADIR can be .. to test without installing.
#MAGMADIR     ?= ..

# Configuración de Mario
MAGMADIR     = /media/mario/G/MAGMA/magma-2.3.0
CUDADIR      = /usr/local/cuda-9.1
OPENBLASDIR  = /usr/include/openblas

# # Configuración de Saúl
# MAGMADIR     = /usr/local/magma
# CUDADIR      = /usr/lib/cuda
# OPENBLASDIR  = /usr/lib/x86_64-linux-gnu/openblas

CC            = gcc
LDFLAGS       = -Wall -lm -no-pie


# ----------------------------------------
# Flags and paths to MAGMA, CUDA, and LAPACK/BLAS
MAGMA_CFLAGS     := -DADD_ \
										-I$(MAGMADIR)/include \
										-I$(MAGMADIR)/sparse/include \
										-I$(CUDADIR)/include

MAGMA_F90FLAGS   := -Dmagma_devptr_t="integer(kind=8)" \
										-I$(MAGMADIR)/include

# may be lib instead of lib64 on some systems
MAGMA_LIBS       := -L$(MAGMADIR)/lib -lmagma_sparse -lmagma \
										-L$(CUDADIR)/lib64 -lcublas -lcudart -lcusparse \
										-L$(OPENBLASDIR)/lib -lopenblas
LSOLVER_LIB      := ./lpsolve/liblpsolve55.a -ldl


# ----------------------------------------

all: hit_run

hit_run:
	$(CC)  hit_run.c -o hit_run.o  $(CFLAGS) $(LDFLAGS) $(MAGMA_CFLAGS) $(MAGMA_LIBS) $(LSOLVER_LIB)
clean:
	rm hit_run.o
