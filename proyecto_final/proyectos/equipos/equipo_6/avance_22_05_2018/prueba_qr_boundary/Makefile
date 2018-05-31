# This is a simple standalone example. See README.txt
# Initially it is setup to use OpenBLAS.
# See magma/make.inc for alternate BLAS and LAPACK libraries,
# or use pkg-config as described below.

# Paths where MAGMA, CUDA, and OpenBLAS are installed.
# MAGMADIR can be .. to test without installing.
#MAGMADIR     ?= ..
MAGMADIR     = /media/mario/G/MAGMA/magma-2.3.0
CUDADIR      = /usr/local/cuda-9.1
OPENBLASDIR  = /usr/include/openblas

CC            = gcc
FORT          = gfortran
LD            = gcc
CFLAGS        = -Wall
# needs -fopenmp if MAGMA was compiled with OpenMP
LDFLAGS       = -Wall #-fopenmp


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


# ----------------------------------------
# Alternatively, using pkg-config (see README.txt):
# MAGMA_CFLAGS   := $(shell pkg-config --cflags magma)
#
# MAGMA_F90FLAGS := -Dmagma_devptr_t="integer(kind=8)" \
#                   $(shell pkg-config --cflags-only-I magma)
#
# MAGMA_LIBS     := $(shell pkg-config --libs   magma)


# ----------------------------------------
default:
	@echo "Available make targets are:"
	@echo "  make c         # compiles example_v1, example_v2, example_sparse, example_sparse_operator"
	@echo "  make clean     # deletes executables and object files"

c: qrsolve boundary

clean:
	-rm -f example_v1 example_v2 example_sparse example_sparse_operator example_f  qrsolve boundary *.o *.mod

.SUFFIXES:


# ----------------------------------------
# C example
%.o: %.c
	$(CC) $(CFLAGS) $(MAGMA_CFLAGS) -c -o $@ $<

qrsolve:  qrsolve.o
	$(LD) $(LDFLAGS) -o $@ $^ $(MAGMA_LIBS)

boundary:  boundary.o
	$(LD) $(LDFLAGS) -o $@ $^ $(MAGMA_LIBS)
