
#include <stdio.h>
#include <omp.h>


int main ( ) {

	int soma = 1;

	omp_set_num_threads (4);

	#pragma omp parallel reduction ( * : soma ) 		// ao final todas as somas sao
														// atualizadas na var global
	{
		soma ++;
		printf ("Soma local = %d\n", soma);
	}

	printf ("\n\nSoma global = %d\n", soma);
}


//+, *, & ou |
