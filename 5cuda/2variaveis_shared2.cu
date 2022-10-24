//exemplo analisar o acesso 
//entre global e shared mem



#include <stdio.h>
#include "tempo.h"



__managed__ int somaglobal;


__global__ void varshared()
{
        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        
        //printf("\n GPU - varshared - th %d\n", idx);
        
        __shared__ int soma;
        

        if (idx == 0) soma = 0;

        soma += threadIdx.x;


        __syncthreads();

        printf("\n GPU - idx %d somashared = %d\n", idx, soma);


}



__global__ void varglobal()
{
        int idx = blockIdx.x * blockDim.x + threadIdx.x;

        //printf("\n GPU - varglobal - th %d \n", idx);
        
        //int soma;

        if (idx == 0) somaglobal = 0;        

        somaglobal += threadIdx.x;

        __syncthreads();
        
        printf("\n GPU - idx %d somaglobal = %d\n", idx, somaglobal);

}

 







int main(int argc, char *argv[])
{
    
    tempo1();
    varglobal <<< 2, 3 >>> ();
    cudaDeviceSynchronize();  
    tempo2();
    tempoFinal("mili segundos", argv[0], MSGLOG);



    tempo1();
    varshared <<< 2, 3 >>> ();
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