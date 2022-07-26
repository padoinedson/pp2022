#include <pthread.h>


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define TAM 10

int vetor[TAM];

void mostra_vetor();
void inicializa_vetor();

int main()
{
	int i, pid, s1, s2, s3;
	s1 = 0;
	s2 = 0;
	s3 = 0;

	inicializa_vetor();

	mostra_vetor();

	pid = fork();
	
	sleep(1);

	if (pid != 0) {

		for (i=0;i<5;i++)
			s1 = s1 + vetor[i];

		printf("\nProcesso pai - pid : %d, soma parcial = %d\n",getpid(), s1);

		s3 = s1 + s2;


	}else {

		for (i=5;i<10;i++)
			s2 = s2 + vetor[i];

		printf("\nProcesso filho - pid : %d, soma parcial = %d\n",getpid(), s2);

		s3 = s1 + s2;

	}

	sleep(2);

	if (pid != 0)

		printf("\nProcesso pai, soma total = %d\n\n",s3);
	else

		printf("\nProcesso filho, soma total = %d\n\n",s3);

//observe que cada processo só tem a sua soma

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
		vetor[i] = i;
}

