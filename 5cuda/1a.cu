#include <stdlib.h>
#include <stdio.h>

void CPUFunction()
{
  printf("CPU - rodando ...\n");
}

__global__ void GPUFunction()
{
  printf("GPU - rodando ....\n");
}

int main()
{
  CPUFunction();

  GPUFunction<<<1, 1>>>();

  cudaDeviceSynchronize();
}














  /*
   * The addition of `__global__` signifies that this function
   * should be launced on the GPU.
   */


  /*
   * Add an execution configuration with the <<<...>>> syntax
   * will launch this function as a kernel on the GPU.
   */


  /*
   * `cudaDeviceSynchronize` will block the CPU stream until
   * all GPU kernels have completed.
   */ 