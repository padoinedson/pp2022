
#include <stdio.h>
#include <omp.h>

void fa() {printf ("\n fa  ");}
void fb() {printf ("\n fb  ");}
void fc() {printf ("\n fc  ");}
void fd() {printf ("\n fd  ");}

int main () {

	int i;

	omp_set_num_threads (2);

	#pragma omp parallel 
	{

		printf ("\n \n oi ");            				//vai ser executado por todas as threads

		#pragma omp task					// cada task roda em todas as thread
		fa(); 
		#pragma omp task
		fb();
		#pragma omp taskwait
		fc(); 

		#pragma omp taskwait				// esta task espera as outras terminarem
		fd(); 

	}

}

//as funcoes fa, fb + fc e fd podem rodar em paralelo, porem a  fb e fc devem rodar em sequencia

