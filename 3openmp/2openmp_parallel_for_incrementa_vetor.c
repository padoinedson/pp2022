#include <stdio.h>
#include <omp.h>

#define TAM 10

int vetor[TAM];

void inicializa_vetor();
void mostra_vetor();


int main () {

	int i;

	omp_set_num_threads (3);

    inicializa_vetor();
    
	mostra_vetor();
	

	#pragma omp parallel for private (i)  
	for(i=0; i<TAM; i++) {	
            printf("thread %d executa o i = %d \n",	omp_get_thread_num(), i);
            vetor[i] ++;
		}

	mostra_vetor();

}




void mostra_vetor()
{
        int z;
        printf("\n v e t o r \n");
        for (z=0; z < TAM; z ++){
                printf("\n Posicao %d - valor %d", z, vetor[z]);
        }
	printf("\n\n\n");
}

void inicializa_vetor()
{
        int z;
        printf("\n inicializando vetor ...\n");
        for (z=0; z < TAM; z ++)
                vetor[z] = z;
}