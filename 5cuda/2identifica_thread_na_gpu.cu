#include <stdio.h>

__global__ void printNumber()
{

            //threadIdx.x numero da th dentro do bloco
    printf("\n GPU - thread numero = %d  foi criada", threadIdx.x);

}


int main()
{

    printf("\n CPU - programa iniciou");

    printNumber<<<2, 4>>>();

    cudaDeviceSynchronize();

    printf("\n CPU - programa finalizou\n\n");
}



//video 3 and 4


