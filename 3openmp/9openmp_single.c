#include <stdio.h>
#include <omp.h>

int main () {


	omp_set_num_threads (6);

	//cuidado - resultado errado
	printf ("Foram criadas %d threads  - ERRADO \n", omp_get_num_threads());



	//cuidado - resultado certo
	#pragma omp parallel 
	{
		#pragma omp single
			printf ("Foram criadas %d threads \n", omp_get_num_threads());
	}

}




//topics
//omp parallel
