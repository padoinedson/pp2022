#include <stdio.h>
#include <cuda.h>




//------Kernel que sera executado na GPU
__global__ void incrementa_valor(int *num)
{
  	int idx = blockIdx.x * blockDim.x + threadIdx.x;
  	
	printf("\n GPU - thread numero = %d  --  num = %d", idx, num);

	atomicAdd(num, 1);
}




int main(int argc, char *argv[0])
{
	//-----cria uma var do tipo ponteiro
	int *num;


	//-----aloca 4 bytes na memória RAM e na GPU
	//4 é qtde de bytes de um inteiro = sizeof(int)
  	cudaMallocManaged(&num, 4);   


	//-----inicializa endereço do ponteiro com 0
  	*num = 0;

	//-----exibe valor inicial
	printf("\n CPU - programa iniciou - num = %d \n\n", *num);

	//-----executa a função incrementa_valor na GPU com 4 threads 
	incrementa_valor <<< 2, 2 >>> (num);

	//-----cria uma barreira - espera todas as threads finalizarem
	cudaDeviceSynchronize();
 
	//-----exibe resultado
	printf("\n\n\n CPU - programa finalizou - num = %d \n\n\n", *num);
 }


