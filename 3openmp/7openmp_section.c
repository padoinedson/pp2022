
#include <stdio.h>
#include <omp.h>

void fa() {printf ("\n fa  ");}
void fb() {printf ("\n fb  ");}
void fc() {printf ("\n fc  ");}
void fd() {printf ("\n fd  ");}

int main () {

	int i;

	omp_set_num_threads (4);

	#pragma omp parallel 
	{

		printf ("\n oi  ");            				//vai ser executado por todas as threads

		 #pragma omp sections 				// cada secao roda em uma thread
		 {
		   	{ 	fa(); }
			#pragma omp section
			{ 	fb();
				fc(); }
			#pragma omp section
			{ 	fd(); }
		 }


	}

}

//as funcoes fa, fb + fc e fd podem rodar em paralelo, porem a  fb e fc devem rodar em sequencia

//http://bisqwit.iki.fi/story/howto/openmp/
