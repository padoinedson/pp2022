#include <stdio.h>
#include <cuda.h>

#define TAM 10


//-----aloca memória global - na RAM e na GPU
__managed__ int vetor[TAM];




//------Kernel que sera executado na GPU
__global__ void incrementa_vetor(int *s)
{
  	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	printf("\n GPU --- somando posição [%d] ", idx);
	atomicAdd(s, vetor[idx]);
}




int main(int argc, char *argv[0])
{

	int i;

	//-----cria uma var do tipo ponteiro
	int *soma;
	//-----aloca 4 bytes na memória RAM e na GPU
	//4 é qtde de bytes de um inteiro = sizeof(int)
  	cudaMallocManaged(&soma, 4); 
	//-----inicializa endereço do ponteiro com 0
	*soma = 0;


	// Initializa vetor na CPU
	for (i=0; i<TAM; i++){ 
		vetor[i] =  i;			
	}

	//-----programa principal exibe o vetor inicial
	for (i=0; i<TAM; i++){ 
		printf("\n CPU --- vet[%2d] = %2d", i, vetor[i]);
	}
	printf("\n");

 							
	//-----executa a função incrementa_vetor na GPU com 10 threads 
	incrementa_vetor <<< 2, 5 >>> (soma);
	
	//-----cria uma barreira - espera todas as threads finalizarem
	cudaDeviceSynchronize();
 

	//-----programa principal exibe o vetor resultado	
	printf("\n\n CPU --- soma = %d ", *soma);

	printf("\n");

}




