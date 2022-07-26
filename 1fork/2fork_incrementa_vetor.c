#include <pthread.h>


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


#define TAM 10

int vetor[TAM];

void mostra_vetor();
void mostra_vetorfinal();
void inicializa_vetor();

int main()
{
	int i, pid, x, y, n;
	x = 0;
	y = 0;

	inicializa_vetor();

	mostra_vetor();

	pid = fork();
	

	if (pid != 0) {
		printf("\nProcesso pai - pid : %d - calcula de 0 a 5\n", getpid() ) ;

		for (i=0;i<5;i++)
			vetor[i] = vetor[i] + 1000;

	}else {

		printf("\nProcesso filho - pid : %d - calcula de 5 a 10\n", getpid() );

		for (i=5;i<10;i++)
			vetor[i] = vetor[i]+ 1000;
	}

	sleep(4);

	if (pid == 0)
		mostra_vetorfinal();
	else
		mostra_vetorfinal();

//observe que cada processo só trabalha no seu vetor

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


void mostra_vetorfinal()
{
        int z;
        printf("\n v e t o r \n");
        for (z=0; z < TAM; z ++){
                printf(" %d ", vetor[z]);
        }
	printf("\n\n\n");
}



void inicializa_vetor()
{
	int i;
	for (i=0; i<TAM; i++)
		vetor[i] = i;
}

