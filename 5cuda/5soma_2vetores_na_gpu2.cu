//versao 2 - qtde de dados < qtde de threads - 7 < 10
//limite


#include <stdio.h>
#include <cuda.h>

#define TAM 7


//-----aloca memória global - na RAM e na GPU
__managed__ int vetorA[TAM];
__managed__ int vetorB[TAM];
__managed__ int vetorC[TAM];


//------Kernel que sera executado na GPU
__global__ void soma_vetor()
{
  	int idx = blockIdx.x * blockDim.x + threadIdx.x;

	if (idx < TAM){   // limita a qtde de threads
		vetorC[idx] = vetorA[idx] + vetorB[idx];
		printf("\n GPU - thread = %d  bloco = %d somando ", idx, blockIdx.x);
	}
}




int main(int argc, char *argv[0])
{

    srand(time(NULL));
    
	int i;
 

	// Initializa vetor na CPU
	for (i=0; i<TAM; i++){ 
		vetorA[i] =  rand() % 100;		
		vetorB[i] =  rand() % 100;	
	}

	//-----programa principal exibe o vetor inicial
	for (i=0; i<TAM; i++){ 
		printf("\n CPU - i = %d - vetorA = %2d  -  vetorB = %2d", i, vetorA[i], vetorB[i]);
	}
	printf("\n");
				
	//-----executa a função incrementa_vetor na GPU com 10 threads 
	soma_vetor <<< 2, 5 >>> ();
	
	//-----cria uma barreira - espera todas as threads finalizarem
	cudaDeviceSynchronize();
 

	//-----programa principal exibe o vetor resultado	
	for (i=0; i<TAM; i++){ 
		printf("\n CPU - i = %d - vetorC = %4d", i, vetorC[i]);
	}
	printf("\n");

}




