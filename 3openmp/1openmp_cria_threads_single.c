//exibir o numero de cores 
#include <stdio.h>
#include <omp.h>

int main ( ) {

	omp_set_num_threads (5);

	#pragma omp parallel
	{
	
	printf ("Thread omp %d criada \n", omp_get_thread_num());


		#pragma omp single 
		{
			printf ("Numero de processadores/cores = %d \n", 
			omp_get_num_procs());

		 	printf ("Foram criadas %d threads omp\n", 
		 	omp_get_num_threads());
		}
	}
	

}

