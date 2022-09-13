#include <stdio.h>
#include <omp.h>


int main ( ) {

	//omp_set_num_threads (4); 
	//export OMP_NUM_THREADS=4

	printf ("parte 1 - sequencial\n");
	 	

	#pragma omp parallel num_threads (7)	 	
	//#pragma omp parallel 
	{
	 	printf ("parte 2 - paralela - Thread %d criada \n", omp_get_thread_num());
		//sleep(30);
	}



	printf ("parte 3 - sequencial\n");
}


//duas funcoes
//set_num_threads
//get_thread_num

