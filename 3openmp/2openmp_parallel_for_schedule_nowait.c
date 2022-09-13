
#include <stdio.h>
#include <omp.h>
#include "tempo.h"

#define TH 2


void work();
int main(int argc, char *argv[])
{
	int i;

	omp_set_num_threads (TH);
	tempo1();

	#pragma omp parallel 
	{
	
		#pragma omp for nowait private (i) 
		for(i=0; i<TH; i++) {	
              		printf("thread %d atua no = %d \n", omp_get_thread_num(), i);
			work();
			tempo2();
			tempoFinal("mili segundos", argv[0], MSGLOG);

		}
	printf("\n end thread %d", omp_get_thread_num());
	}
}

void work() {

	int lim,i,x,y;
	if (omp_get_thread_num() == 0)
		lim = 1000;
	else
		lim = 10 ;
	printf("thread %d -- lim = %d \n\n", omp_get_thread_num(), lim);

	int w=0;
	for (i=0; i < lim; i++){
	for (x=0; x < lim; x++){		
	for (y=0; y < lim; y++){
		w++;
	}}}	
}



