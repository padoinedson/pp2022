#include <stdlib.h>
#include <stdio.h>



//------Kernel que sera executado na GPU
__global__ void mostra1()
{
 
	printf("\n thread numero = %d  foi criada", threadIdx.x);

}




int main(int argc, char *argv[0])
{


 	printf("\n CPU - programa iniciou \n\n\n");

		//-----executa a função na GPU com n threads 
		//----- cria n blocos com n threads em cada bloco
	mostra1 <<< 2, 5 >>> ();


		//-----cria uma barreira - espera todas as threads finalizarem
	cudaDeviceSynchronize();
 

  	printf("\n\n\n CPU - programa finalizou \n\n\n");



 }


