#include <stdlib.h>
#include <stdio.h>

void CPUFunction()
{
  printf("CPU - rodando ....\n");
}

__global__ void GPUFunction()
{
  printf("CPU - rodando ....\n");
}

int main()
{
  CPUFunction();

  GPUFunction<<<1, 1>>>();

//  cudaDeviceSynchronize();
}


/*
   * sem a diretiva `cudaDeviceSynchronize` o programa principal não espera o Kernel que está rodando na GPU
*/ 