#include <stdio.h>
#include "tempo.h"





 

__device__ __constant__  int vetor[4] = {1,2,3,4};


__global__ void mostra()
{

  printf("%d\n", vetor[3]);
}




int main(int argc, char *argv[])
{
    
  mostra<<<1,1>>>();

  cudaDeviceSynchronize();

}












/*
 

 ## Qualificadores de tipo de variável

__device__ 
  - define uma variável no espaço de memória global da GPU 
  - ela é acessível por todas as threads de um grid e também a partir da CPU  
  - tempo de vida é o da aplicação  

__constant__ 
  - define uma variável no espaço de memória constante da GPU
  - constant memory only accessible on the device

__shared__ 
  - define uma uma var na memória compartilhada da GPU
  - ela é acessível apenas para as threads do mesmo bloco
  - tempo de vida é o do bloco

__managed__ 
  - permite o uso de "Memória unificada"


  
   */




/*
#include <stdio.h>

__device__ float c_array[10];
 
__global__ void kernel(float* d_array)
{ 

    d_array[0] = c_array[0]; 
}
 
int main()
{

    float* d_array = 0;
    
    float h_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};   
    
    cudaMalloc((void**)&d_array, 10 * sizeof(float));
    
    cudaMemcpyToSymbol("c_array", h_array, sizeof(float)*10, 0, cudaMemcpyHostToDevice );
    
    kernel<<< 1, 1 >>>(d_array);

}


=========================



 __constant__ int soma;
 

__global__ void mostra2()
{
        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        
        printf("\n GPU - varconstant = %d\n", idx);
        
        int N = 2<<20;
        
        int x =0;

        
        for (int i= 0; i < N; i++) 
            x += soma;


        printf("\n GPU - soma = %d\n", soma);

}




  int h_soma = 10;   
  cudaMemcpyToSymbol(soma, h_soma, sizeof(int)*1, 0, cudaMemcpyHostToDevice );
  mostra<<<1,1>>>();
  cudaDeviceSynchronize();

*/