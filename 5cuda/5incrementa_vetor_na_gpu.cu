#include <stdio.h>
#include <cuda.h>

#define TAM 10


//-----aloca memória global - na RAM e na GPU
__managed__ int vetor[TAM];




//------Kernel que sera executado na GPU
__global__ void incrementa_vetor()
{
  	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	
	vetor[idx] = vetor[idx] + 1000;
}




int main(int argc, char *argv[0])
{

	int i;

	// Initializa vetor na CPU
	for (i=0; i<TAM; i++){ 
		vetor[i] =  i;			
	}

	//-----programa principal exibe o vetor inicial
	for (i=0; i<TAM; i++){ 
		printf("\n CPU i = %2d - vetor = %2d", i, vetor[i]);
	}
	printf("\n");

 							
	//-----executa a função incrementa_vetor na GPU com 10 threads 
	incrementa_vetor <<< 2, 5 >>> ();
	
	//-----cria uma barreira - espera todas as threads finalizarem
	cudaDeviceSynchronize();
 

	//-----programa principal exibe o vetor resultado	
	for (i=0; i<TAM; i++){ 
		printf("\n CPU i = %d - vetor = %d", i, vetor[i]);
	}
	printf("\n");

}




