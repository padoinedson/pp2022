/*


*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


#define TAM 20

int vetor[TAM];

void mostra_vetor();
void inicializa_vetor();

int main()
{
	int i;

	inicializa_vetor();

	mostra_vetor();

	for (i=0;i<TAM;i++)
		vetor[i] = vetor[i] + 1000;

	mostra_vetor();
}


void mostra_vetor()
{
        int z;
        printf("\n v e t o r \n");
        for (z=0; z < TAM; z ++){
                printf("\n Posicao %d - valor %d", z, vetor[z]);
        }
	printf("\n\n\n");
}


void inicializa_vetor()
{
	int i;
	for (i=0; i<TAM; i++)
		vetor[i] = rand() % TAM;
}

