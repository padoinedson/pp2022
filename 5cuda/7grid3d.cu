#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // rand(), srand()
//#include "tempo.h"


#define L 4
#define C L
#define P L

__managed__ int cubo[C][L][P];

__global__ void inicializa_cubo()
{        
        
        int idx =  threadIdx.x;
        int idy =  threadIdx.y;
        int idz =  threadIdx.z;

        printf("\n GPU - inicializando - L= %d C= %d P= %d \n", idx, idy, idz);

        cubo[idx][idy][idz] = idx + idy + idz;
}



__global__ void dobro()
{
        int idx =  threadIdx.x;
        int idy =  threadIdx.y;
        int idz =  threadIdx.z;

        printf("\n GPU -  calculando...\n");

        cubo[idx][idy][idz] *= 2;

}



void mostra_cubo();


int main(int argc, char *argv[])
{


    //tempo1();
    


    //kernel com um bloco de L * C * P * 1 threads
    int numBlocks = 1;
    dim3 threadsPerBlock(L, C, P);
  

    inicializa_cubo <<< numBlocks, threadsPerBlock >>> ();
    cudaDeviceSynchronize();  
    mostra_cubo();

    dobro <<< numBlocks, threadsPerBlock >>> ();
    cudaDeviceSynchronize();
    mostra_cubo();

    //tempo2();

    //tempoFinal("mili segundos", argv[0], MSGLOG);
}




void mostra_cubo()
{
    int z, v, x;
        printf("\n CPU - C U B O \n");

        for (z=0; z < L; z ++){
            for (v=0; v < C; v++) {
                for (x=0; x < P; x++){
                    printf(" %4d", cubo[z][v][x]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n\n\n");
    
}






//https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#thread-hierarchy

