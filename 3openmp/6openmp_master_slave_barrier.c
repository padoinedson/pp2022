#include <stdio.h>
#include <omp.h>

int main ( ) {

	omp_set_num_threads (3);

	#pragma omp parallel 
	{
		#pragma omp master
			 printf ("Mestre inicia - total de threads %d \n", omp_get_num_threads());

		#pragma omp slave
			 printf ("     Escravo %d  inicia\n", omp_get_thread_num());

		#pragma omp master 
			 printf ("Mestre termina\n");

		#pragma omp slave 
			 printf ("     Escravo %d termina\n", omp_get_thread_num());


	#pragma omp barrier
	printf ("Todos terminaram \n");


	}

}



//topics
//master
//slave
//barrier
