// quantidade de thread > que o tam dos dados
// usar o N como limitante no kernel da GPU



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
  int i;
  i = blockIdx.x * blockDim.x + threadIdx.x;

  if (i < N)
  {
    a[i] *= 2;
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
  int N = 10;
  int *a;

  size_t size = N * sizeof(int);


  cudaMallocManaged(&a, size);

  init(a, N);

  size_t threads_per_block = 3;
  size_t number_of_blocks = 4;


  printf("\n CPU - N = %d \n", N);

  printf("\n CPU - numberOfBlocks = %ld\n", number_of_blocks);

  printf("\n CPU - threadPerBlock = %ld\n", threads_per_block);

  printf("\n CPU - totalThread = %ld\n\n", threads_per_block*number_of_blocks);



  doubleElements<<<number_of_blocks, threads_per_block>>>(a, N);
  cudaDeviceSynchronize();

  bool areDoubled = checkElementsAreDoubled(a, N);
  printf(" CPU - All elements were doubled? %s\n", areDoubled ? "TRUE" : "FALSE");



  cudaFree(a);
}




//video 5

//https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#thread-hierarchy
//On current GPUs, a thread block may contain up to 1024 threads