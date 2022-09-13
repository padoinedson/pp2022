#include <stdio.h>
#include <omp.h>


int main ( ) {

	int y = 0;			        				//y  eh uma var compartilhada

	omp_set_num_threads (3);


	#pragma omp parallel                     	//as duas expressoes sao semelhante 
//	#pragma omp parallel shared (y)				//compartilha y para cada thread
	{
		y ++;
		printf ("\t y = %d na th = %d\n", y, omp_get_thread_num());

	}

	printf ("y = %d no bloco sequencial \n\n", y);
}


