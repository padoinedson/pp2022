#include <stdio.h>
#include <omp.h>


int main ( ) {


	int y = 330;			        			//y  eh uma var compartilhada

	omp_set_num_threads (3);


	#pragma omp parallel firstprivate (y)		//copia o valor da var y global para cada thread e ele passa ser local
	{

		y ++;
		printf ("\t y = %d na th = %d\n", y, omp_get_thread_num());

	}

	printf ("y = %d no bloco sequencial \n\n", y);
}

