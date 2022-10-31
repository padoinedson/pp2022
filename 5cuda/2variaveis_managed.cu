#include <stdio.h>

#define L 10


__managed__ int vetor[L];

        // managed - Memória unificada 
        //- os dados sao alocados nas e mem (RAM e GPU)
        //- os dados sao sincronizados entre as mem





__global__ void inicializa_vetor()
{
        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        
        printf("\n GPU - inicializando - L= %d\n", idx);
        
        vetor[idx] = idx;

}



__global__ void dobro()
{
        int idx = blockIdx.x * blockDim.x + threadIdx.x;

        printf("\n GPU - calculando - th %d \n", idx);
        
        vetor[idx] = vetor[idx] * 2;

}


__host__ void mostra_vetor()
{
        int z;
        printf("\n CPU - V E T O R \n");
        for (z=0; z < L; z ++){
                printf("  %3d", vetor[z]);
        }
  printf("\n\n\n");
}









int main(int argc, char *argv[])
{
    

    inicializa_vetor <<< 2, 5 >>> ();
    cudaDeviceSynchronize();  
    mostra_vetor();


    dobro <<< 2, 5 >>> ();
    cudaDeviceSynchronize();
    mostra_vetor();



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



In terms of speed:

1st : Register file
2nd : Shared Memory
3rd : Constant Memory
4th : Texture Memory
Last place: Local Memory and Global Memory

  
   */