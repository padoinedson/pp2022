#include <stdio.h>
#include <omp.h>

#define TAM 2
int main ( ) {
int k,j,i;


	omp_set_num_threads (5);


	#pragma omp parallel for collapse(1)
	for (k=0; k < TAM; k++)
	for (j=0; j < TAM; j++)
	for (i=0; i < TAM; i++) {
		printf (" thread %d  -k %d - j %d - i %d\n", omp_get_thread_num(), k , j , i);
	}
			
 	printf ("Todos terminaram \n");

}

