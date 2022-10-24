#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // rand(), srand()
//#include "tempo.h"


#define L 10

__managed__ int vetor[L];


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


void mostra_vetor();



int main(int argc, char *argv[])
{

    //tempo1();
    

    inicializa_vetor <<< 2, 5 >>> ();
    cudaDeviceSynchronize();  
    mostra_vetor();


    dobro <<< 2, 5 >>> ();
    cudaDeviceSynchronize();
    mostra_vetor();

    //tempo2();

    //tempoFinal("mili segundos", argv[0], MSGLOG);

}


void mostra_vetor()
{
        int z;
        printf("\n CPU - V E T O R \n");
        for (z=0; z < L; z ++){
                printf("  %3d", vetor[z]);
        }
	printf("\n\n\n");
}










//https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#thread-hierarchy




