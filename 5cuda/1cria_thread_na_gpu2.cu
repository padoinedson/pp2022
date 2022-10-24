#include <stdlib.h>
#include <stdio.h>



__host__ void mostra()
{
 
 	printf("\n CPU - programa iniciou \n\n\n");  	

}



__global__ void mostra1()
{
  	
	printf("\n GPU - thread numero = %d  foi criada", threadIdx.x);
//	mostra2 <<< 1, 1 >>> ();

}



__device__ void mostra2()
{
  	
	printf("\n GPU - thread numero = %d  foi criada", threadIdx.x);

}





int main(int argc, char *argv[0])
{


	mostra();

	mostra1 <<< 1, 1 >>> ();

 	cudaDeviceSynchronize();
  
  	printf("\n\n\n CPU - programa finalizou \n\n\n");

 }






/* Qualificadores de tipo de função


__global__  
	- define uma função que é executada na GPU 
	- é chamada a partir da CPU  

__device__  
	- define uma função que será executada na GPU 
	- só pode ser chamada a partir da GPU  

__host__ 
	- define uma função que será executada na CPU 
	- só pode ser chamada a partir da CPU  


*/