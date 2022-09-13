#include <stdio.h>
#include <omp.h>

int main () {

	int i;

	omp_set_num_threads (3);

	#pragma omp parallel 
	{
	

		#pragma omp for private (i)  
		for(i=0; i<10; i++) {	
              		printf("thread %d executa o i = %d \n",	omp_get_thread_num(), i);
		}
	}

}


