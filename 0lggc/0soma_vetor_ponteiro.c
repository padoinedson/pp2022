#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>
#include <stdlib.h>


#define TAM 10

int vetor[TAM];

void inicializa_vetor();
void mostra_vetor();

int main()
{
	
	printf("\n INTEIRO 	 = %ld\n",sizeof(int));
	int i,j;
 
	inicializa_vetor();

	mostra_vetor();

	int *soma;
	soma  = (int *) malloc(sizeof(int));
	*soma = 0;					

	for (i=0;i<TAM;i++)
		*soma = *soma + vetor[i];

	printf("\nSoma = %d\n",*soma);
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
        int z;
        printf("\n inicializando vetor ...\n");
        for (z=0; z < TAM; z ++)
                vetor[z] = rand()%10;
}

