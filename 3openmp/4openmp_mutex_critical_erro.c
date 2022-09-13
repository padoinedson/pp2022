#include <stdio.h>
#include <omp.h>


int main ( ) {

	omp_set_num_threads (10000);  


	int x;
 	x = 0;

 	#pragma omp parallel shared(x)
 	{
 	 	 	//#pragma omp critical
 	 	 	x = x + 1;
		 	printf ("x = %d \n", x);
 	 }

	printf ("valor de x fora das threads = %d \n", x);

}

 
