#include <stdio.h>
#include <string.h>
#include "tempo.h"

#define L 500
#define C 500

float m1[C][L], m2[C][L], m3[C][L];

void inicializa_matriz();
void mostra_matriz();
void multiplica();
void mostra_resultado();

int main(int argc, char *argv[])
{

	inicializa_matriz();

//	mostra_matriz();

	tempo1();

	multiplica();

	tempo2();

//	mostra_resultado();

	tempoFinal("mili segundos", argv[0], MSGLOG);

}


void multiplica()

{	
	int i, j , v;

        printf("\n  multiplicando.... \n");
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
        	        printf("  %3f", m1[z][v]);
		}
        	printf("\n");
	}
	printf("\n\n\n");
	
        printf("\n  M.2 \n");
	for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf("  %3f", m2[z][v]);
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
        	        printf(" %4f", m3[z][v]);
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
			m1[z][v] = z+1.9876;
			m2[z][v] = v+2.4680;
			m3[z][v] = 0;
		}
}







