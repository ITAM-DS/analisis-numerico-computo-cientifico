```
%load_ext Cython

%%cython --annotate
from libc.stdio cimport *
from libc.stdlib cimport *

file_name="Graph1.txt"
cdef void adjacency_matrix (int am[5][5]):
    cdef int i, j
    cdef int nv=5
    cdef FILE * pFile
    pFile=fopen(file_name, "r")
    
    for i from 0 <= i < nv by 1:{
        print(i)
    }
    print(file_name)
    print("hello world")

```
