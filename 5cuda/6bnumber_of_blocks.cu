// usar o N como limitante no kernel da GPU
// calculando o numero de blocos 



#include <stdio.h>

__global__ void initializeElementsTo(int initialValue, int *a, int N)
{
  int i = threadIdx.x + blockIdx.x * blockDim.x;
  if (i < N)
  {
    a[i] = initialValue;
  }
}

int main()
{
 

  int N = 1000;

  int *a;
  size_t size = N * sizeof(int);

  cudaMallocManaged(&a, size);

  /*
   * Assume we have reason to want the number of threads
   * fixed at `256`: do not modify `threads_per_block`.
   */

  size_t threads_per_block = 256;

  /*
   * The following is idiomatic CUDA to make sure there are at
   * least as many threads in the grid as there are `N` elements.
   */




  size_t number_of_blocks = (N + threads_per_block - 1) / threads_per_block;



  printf("\n CPU - N = %d \n", N);

  printf("\n CPU - numberOfBlocks = %ld\n", number_of_blocks);

  printf("\n CPU - threadPerBlock = %ld\n", threads_per_block);

  printf("\n CPU - totalThread = %ld\n\n", threads_per_block*number_of_blocks);






  int initialValue = 6;

  initializeElementsTo<<<number_of_blocks, threads_per_block>>>(initialValue, a, N);
  cudaDeviceSynchronize();


  for (int i = 0; i < N; ++i)
  {
    if(a[i] != initialValue)
    {
      printf("FAILURE: target value: %d\t a[%d]: %d\n", initialValue, i, a[i]);
      cudaFree(a);
      exit(1);
    }
  }
  printf("SUCCESS!\n");

  cudaFree(a);
}

