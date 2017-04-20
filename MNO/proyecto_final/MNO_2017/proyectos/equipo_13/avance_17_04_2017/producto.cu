// ejemplo obtenido de https:/people.cs.pitt.edu/~melhem/courses/xx45p/cuda_examples.pdf

_global_void saxpy_parallel(int n, float alpha, float *x, float *y)
{
int i = blockIdx.x*blockDim.x + threadIdx.x;
if( i<n ) y[i] = alpha*x[i] + y[i];
}
// Invoke parallel SAXPY kernel (256 threads per block)\\
int nblocks = (n + 255) / 256;
saxpy_parallel<<<nblocks, 256>>>(n, 2.0, x, y);
