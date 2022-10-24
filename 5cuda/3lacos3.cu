
#include <stdio.h>

__global__ void printNumber()
{
  printf(" GPU - iteration= %d\n", threadIdx.x);
  
}


int main()
{

  printNumber<<<1, 5>>>();

  cudaDeviceSynchronize();

}


