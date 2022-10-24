#include <stdio.h>
#include <cuda.h>



__global__ void dobro(float *a, int N)
{
  	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	if (idx<N) {
	    printf("\n GPU - calculando - th %d \n", idx);
		a[idx] = a[idx] * 2;
	}
}




int main(int argc, char *argv[0])
{

	int i;
	float *a_h;								// pointeiro da RAM 
	float *a_d;  							// pointeiro da GPU
	const int N = 10;  						// tamanho do vetor
	size_t size = N * sizeof(float);		// qtde de bytes do vetor = 40


	//------aloca memoria na CPU
	a_h = (float *)malloc(size);        		


	//------aloca memoria na GPU
	cudaMalloc((void **) &a_d, size);   		


	// Initializa vetor na CPU
	for (i=0; i<N; i++){ 
		a_h[i] = (float)i+2;			
	}

	// exibe vetor	
	for (i=0; i<N; i++){ 
		printf("\n CPU i = %d - vetor =%3f", i, a_h[i]);
	}


	//------copia variaval da RAM para a GPU  
	cudaMemcpy(a_d, a_h, size, cudaMemcpyHostToDevice);
									

	//------define qtde de blocos e qtde de threads por bloco
	int block_size = 10;          	
	int n_blocks = 1;   	        
	printf("\n\nqtde de blocos:   %d",n_blocks);						
	printf("\ntamanho do bloco: %d\n\n", block_size);



	//------executa o kernel na GPU
	dobro <<< n_blocks, block_size >>> (a_d, N);


	//------copia variaval da GPU para a RAM
	cudaMemcpy(a_h, a_d, size, cudaMemcpyDeviceToHost);


	//-----exibe resultado	
	for (i=0; i<N; i++){ 
		printf("\n CPU i = %d - vetor =%3f", i, a_h[i]);
	}

    //---libera memória RAM
	free(a_h); 

    //---libera memória da GPU
	cudaFree(a_d); 

}




