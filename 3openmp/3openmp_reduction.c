#include <stdlib.h>  // rand(), srand()
#include <time.h> 

#include <stdio.h>
#include <omp.h>


int main ( ) {

	srand(time(NULL));

	int var = 1;

	omp_set_num_threads (5);

	#pragma omp parallel reduction ( + : var ) 	// ao final todas as var sao
												// atualizadas na var global
	{
		var = rand() % 10; 
		printf ("var local = %d\n", var);
	}

	printf ("\n\nvar global = %d\n", var);
}


//+, *, & ou |
