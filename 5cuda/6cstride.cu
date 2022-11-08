// quantidade de thread < que o tam dos dados

#include <stdio.h>

void init(int *a, int N)
{
  int i;
  for (i = 0; i < N; ++i)
  {
    a[i] = i;
  }
}

__global__
void doubleElements(int *a, int N)
{

  /*
   * Use a grid-stride loop so each thread does work
   * on more than one element in the array.
   */

  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = gridDim.x * blockDim.x;

  for (int i = idx; i < N; i += stride)
  {
    a[i] *= 2;
    printf ("\n GPU - kernel %d - stride %d index %d value %d", idx, stride, i, a[i]);
  }
}

bool checkElementsAreDoubled(int *a, int N)
{
  int i;
  for (i = 0; i < N; ++i)
  {
    if (a[i] != i*2) return false;
  }
  return true;
}

int main()
{
  int N = 32;
  int *a;

  size_t size = N * sizeof(int);
  cudaMallocManaged(&a, size);

  init(a, N);

  size_t threads_per_block = 4;
  size_t number_of_blocks = 2;


  printf("\n CPU - N = %d \n", N);

  printf("\n CPU - numberOfBlocks = %ld\n", number_of_blocks);

  printf("\n CPU - threadPerBlock = %ld\n", threads_per_block);

  printf("\n CPU - totalThread = %ld\n\n", threads_per_block*number_of_blocks);





  doubleElements<<<number_of_blocks, threads_per_block>>>(a, N);
  cudaDeviceSynchronize();

  bool areDoubled = checkElementsAreDoubled(a, N);
  printf("\n CPU - All elements were doubled? %s\n", areDoubled ? "TRUE" : "FALSE");

  cudaFree(a);
}


//video 6