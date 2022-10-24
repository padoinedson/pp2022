#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // rand(), srand()
//#include "tempo.h"


#define L 5
#define C L

__managed__ int matriz[C][L];


__global__ void inicializa_matriz()
{        
        

        int idx =  threadIdx.x;
        int idy =  threadIdx.y;

        printf("\n GPU - inicializando - L= %d C= %d \n", idx, idy);

        matriz[idx][idy] = idx;
}



__global__ void dobro()
{
        int idx =  threadIdx.x;
        int idy =  threadIdx.y;

        printf("\n GPU -  calculando...\n");

        matriz[idx][idy] *= 2;

}



void mostra_matriz();


int main(int argc, char *argv[])
{

    //tempo1();
    


    //kernel com um bloco de L * C * 1 threads
    int numBlocks = 1;
    dim3 threadsPerBlock(L, C);
  
    inicializa_matriz <<< numBlocks, threadsPerBlock >>> ();
    cudaDeviceSynchronize();  
    mostra_matriz();

    dobro <<< numBlocks, threadsPerBlock >>> ();
    cudaDeviceSynchronize();
    mostra_matriz();


    //tempo2();

    //tempoFinal("mili segundos", argv[0], MSGLOG);

}



void mostra_matriz()
{
        int z, v;
        printf("\n CPU - M A T R I Z \n");

        for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf("  %3d", matriz[z][v]);
		}
        	printf("\n");
	}
	printf("\n\n\n");
	
}









//https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#thread-hierarchy

