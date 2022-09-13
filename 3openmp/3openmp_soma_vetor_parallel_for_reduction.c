#include <stdio.h>
#include <omp.h>

int main () {

	int vet [10], i, somatorio = 0;

	omp_set_num_threads (3);


//inicializar vetor em paralelo
	#pragma omp parallel for private (i) 
		for(i=0; i<10; i++) {	
			vet[i] = i;
              		printf("thread %d inicializou a posicao = %d \n", omp_get_thread_num(), vet[i]);
		}

	printf("\n");


//somar vetor em paralelo	
	#pragma omp parallel for private (i) reduction ( + : somatorio) 
		for (i=0; i<10; i++) {
		     somatorio += vet[i];
		     printf("thread %d Soma parcial : %d \n", omp_get_thread_num(), somatorio);
		}

	printf("Somatorio : %d\n", somatorio) ;
}


