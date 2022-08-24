#include <stdio.h>
#include <omp.h>
#include "tempo.h"

#define L 2000
#define C 2000

int m1[C][L], m2[C][L], m3[C][L];

void inicializa_matriz();
void mostra_matriz();
void multiplica();
void mostra_resultado();

int main(int argc, char *argv[])
{

	omp_set_num_threads (4);

	#pragma omp parallel
	{
		#pragma omp single 
		{
			printf ("Numero de cores = %d \n", 
			omp_get_num_procs());

		 	printf ("Foram criadas %d threads omp\n", 
		 	omp_get_num_threads());
		}
	}

	inicializa_matriz();

	//mostra_matriz();

	tempo1();

	multiplica();

	tempo2();

	//mostra_resultado();

	tempoFinal("mili segundos", argv[0], MSGLOG);

}


void multiplica()

{	
	int i, j , v;
	#pragma omp parallel for private (i, j, v)

	for (i = 0; i < L; i++)
		for (j = 0; j < C; j++)
			for (v = 0; v < C; v++)
				m3[i][j] = m3[i][j] + m1[i][v] * m2[v][j];

}

void mostra_matriz()
{
        int z, v;
        printf("\n  M A T R I Z \n");


        printf("\n  M.1 \n");
        for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf("  %3d", m1[z][v]);
		}
        	printf("\n");
	}
	printf("\n\n\n");

        printf("\n  M.2 \n");	
	for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf("  %3d", m2[z][v]);
		}
        	printf("\n");
	}
}
void mostra_resultado()
{
	int z, v;
        printf("\n  M A T R I Z  R E S U L T A D O \n");

        for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf(" %4d", m3[z][v]);
		}
        	printf("\n");
	}
	printf("\n\n\n");
	
}

void inicializa_matriz()
{
        int z, v;
        printf("\n inicializando matrizes ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			m1[z][v] = z+1;
			m2[z][v] = v+2;
			m3[z][v] = 0;
		}
}

