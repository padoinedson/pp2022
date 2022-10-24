#include <stdio.h>
#include <cuda.h>




//------Kernel que sera executado na GPU
__global__ void soma_numeros(int *num1, int *num2)
{
  	int idx = blockIdx.x * blockDim.x + threadIdx.x;
  	
  	*num1 = *num1 + *num2;
  	
	printf("\n GPU - thread numero = %d  --  num = %d", idx, *num1);

}




int main(int argc, char *argv[0])
{
	//-----cria uma var do tipo ponteiro
	int *num1, *num2;

	//-----aloca 4 bytes na memória RAM e na GPU
  	cudaMallocManaged(&num1, 4);   //sizeof(int)
  	cudaMallocManaged(&num2, 4);   //sizeof(int)

	//-----inicializa endereço do ponteiro com 0
  	*num1 = 4;
  	*num2 = 5;  	

	//-----exibe valor inicial
	printf("\n CPU - programa iniciou - num = %d \n\n", *num1);

	//-----executa a função incrementa_valor na GPU com 4 threads 
	soma_numeros <<< 1, 1 >>> (num1, num2);

	//-----cria uma barreira - espera todas as threads finalizarem
	cudaDeviceSynchronize();
 
	//-----exibe resultado
	printf("\n\n\n CPU - programa finalizou - num = %d \n\n\n", *num1);
 }


