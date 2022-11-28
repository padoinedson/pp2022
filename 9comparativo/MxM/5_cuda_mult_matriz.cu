#include <stdio.h>
#include <cuda.h>
//#include "tempo.h"

const int L = 3; //8000; 
const int C = 3; //8000;


const int TAM_MATRIZ = L * C;

const int BLOCK_SIZE = 3;


void mostra_matriz(int mat[]);
void inicializa_matrizL(int mat[]);
void inicializa_matrizC(int mat[]);

__global__ void matrixMul(int* A, int* B, int* C)
{
	//Using blocks
	int i = blockIdx.y * blockDim.y + threadIdx.y;
	int j = blockIdx.x * blockDim.x + threadIdx.x;

	for(int k = 0; k < L; ++k){
		C[i * L + j] += A[i * L + k] * B[k * L + j];
	}
}

int main(int argc, char** argv)
{

	int* h_A;
	int* h_B;
	int* h_C;

	int* d_A;
	int* d_B;
	int* d_C;
	
	size_t size = TAM_MATRIZ * sizeof(int);

	//alocação memoria RAM
	h_A = (int*)malloc(size);
	h_B = (int*)malloc(size);
	h_C = (int*)malloc(size);

	//inicializa matrizes
	inicializa_matrizL(h_A);
	inicializa_matrizC(h_B);

        printf("\n  M A T R I Z    A \n");
	mostra_matriz(h_A);

        printf("\n  M A T R I Z    B \n");
	mostra_matriz(h_B);

        printf("\n  M A T R I Z    C \n");
	mostra_matriz(h_C);

	//alocação memoria GPU
	cudaMalloc((int**)&d_A, size);
	cudaMalloc((int**)&d_B, size);
	cudaMalloc((int**)&d_C, size);

	//copia matrizes da RAM para GPU
	cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_C, h_C, size, cudaMemcpyHostToDevice);

	//tempo1();

	//Call kernels
	dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
	dim3 dimGrid(L / dimBlock.x, C / dimBlock.y);
	matrixMul<<<dimGrid, dimBlock>>>(d_A, d_B, d_C);

	//tempo2();

	//copia matriz C da GPU para RAM
	cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);


        printf("\n\n\n  M A T R I Z    C \n");
	mostra_matriz(h_C);

	//tempoFinal("mili segundos", argv[0], MSGLOG);

	//libera memorias
	free(h_A);
	free(h_B);
	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);

	return 0;
}

void inicializa_matrizL(int mat[])
{
        int z, v;
        printf("\n inicializando matriz ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			mat[z * C + v] = z+1;
		}
}

void inicializa_matrizC(int mat[])
{
        int z, v;
        printf("\n inicializando matriz ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			mat[z * C + v] = v+2;
		}
}

void mostra_matriz(int mat[])
{
        int z, v;
        for (z=0; z < L; z ++){
		for (v=0; v < L; v++) {
        	        printf(" %4d", mat[z * L + v]);
		}
        	printf("\n");
	}
}
