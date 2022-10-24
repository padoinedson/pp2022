
#include <stdio.h>
#include <cuda.h>


//------Kernel que sera executado na GPU
__global__ void incrementa_valor()
{
           //calcula numero da th geral
           //num_bloco * qtde th_do_bloco + id_th_dentro_bloco

  int idx = blockIdx.x * blockDim.x       + threadIdx.x;
    
  printf("\n GPU - thread id-geral= %d  - id-bloco= %d  - id-dentro-bloco= %d\n ", idx, blockIdx.x, threadIdx.x);

}




int main(int argc, char *argv[0])
{

  printf("\n CPU - programa iniciou \n\n\n");

  //-----executa a função incrementa_valor na GPU com 4 threads 
  //----- cria 2 blocos com 2 threads em cada bloco
  incrementa_valor <<< 2, 2 >>> ();

  //-----cria uma barreira - espera todas as threads finalizarem
  cudaDeviceSynchronize();
 
  //-----exibe resultado
  printf("\n\n\n CPU - programa finalizou \n\n\n");

 }


