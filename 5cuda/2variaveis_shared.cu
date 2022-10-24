//exemplo para comparar o tempo
//entre global e shared mem



#include <stdio.h>
#include "tempo.h"






__global__ void varshared()
{
        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        
        printf("\n GPU - varshared = %d\n", idx);
        
        int N = 2<<20;
         __shared__ int soma;
        

        for (int i= 0; i < N; i++) 
            soma = i;


//        __syncthreads();

        printf("\n GPU - soma = %d\n", soma);


}



__global__ void varglobal()
{
        int idx = blockIdx.x * blockDim.x + threadIdx.x;

        printf("\n GPU - varglobal - th %d \n", idx);
        
        int N = 2<<20;
        int soma;

        for (int i= 0; i < N; i++) 
            soma = i;

        printf("\n GPU - soma = %d\n", soma);

}

 







int main(int argc, char *argv[])
{
    
    tempo1();
    varglobal <<< 1, 1 >>> ();
    cudaDeviceSynchronize();  
    tempo2();
    tempoFinal("mili segundos", argv[0], MSGLOG);



    tempo1();
    varshared <<< 1, 1 >>> ();
    cudaDeviceSynchronize();
    tempo2();
    tempoFinal("mili segundos", argv[0], MSGLOG);

}












/*
 

 ## Qualificadores de tipo de variável

__device__ 
  - define uma variável no espaço de memória global da GPU 
  - ela é acessível por todas as threads de um grid e também a partir da CPU  
  - tempo de vida é o da aplicação  

__constant__ 
  - define uma variável no espaço de memória constante da GPU

__shared__ 
  - define uma uma var na memória compartilhada da GPU
  - ela é acessível apenas para as threads do mesmo bloco
  - tempo de vida é o do bloco

__managed__ 
  - permite o uso de "Memória unificada"


  
   */