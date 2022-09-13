#include <stdio.h>
#include <omp.h>

int main () {

	int i;

	omp_set_num_threads (4);

	#pragma omp parallel 
	{
	
		#pragma omp for private (i) schedule (static, 3)   		// 2 iteracoes para cada th
	 	//#pragma omp for private (i) schedule (dynamic)     	// dinamicamente
		//#pragma omp for private (i) schedule (runtime)     	// seta na var de ambiente OMP_SCHEDULE=4
		for(i=0; i<10; i++) {	
              		printf("thread %d executa o i = %d \n", omp_get_thread_num(), i);
		}
	}
}



//static. Se o programador especificou um valor para chunk, este valor será usado para calcular o tamanho dos chunks e eles serão atribuídos aos fluxos seguindo um Round-Robin. Se não houver um valor especificado, o default é 1. Portanto, é durante a compilação que se determina quais chunks serão executados por quais fluxos.

//runtime  deixa a decisão de escalonamento das iterações para o momento da execução do programa. Neste caso, dever- se-á atribuir à variável de ambiente OMP_SCHEDULE um valor que seja compatível com as opções acima. Por exemplo: setenv OMP_SCHEDULE ‘‘static,10’

