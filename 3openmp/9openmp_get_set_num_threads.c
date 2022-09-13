//criar threads de acordo com o numero de cores 

#include <stdio.h>
#include <omp.h>


int main ( ) {

	#pragma omp single 
	{
		printf ("Numero de processadores/cores = %d \n", omp_get_num_procs());
		int t = omp_get_num_procs();
		omp_set_num_threads (t);
	}

	#pragma omp parallel
	{
	printf ("Thread %d criada \n", omp_get_thread_num());
	}
}

