#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>

#include <sys/wait.h>  //wait
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()

#define TAM 10

int vetor[TAM];

void inicializa_vetor();
void mostra_vetor();

int main()
{
	int i,j;
	int pid, numero_do_segmento;
	int * soma;

	inicializa_vetor();

	mostra_vetor();


    srandom(time(NULL));

	numero_do_segmento = shmget(IPC_PRIVATE, 4, IPC_CREAT | 0644 );  //cria um segmento de 
									 //memoria compartilhada


	if (numero_do_segmento < 0) 
        	printf("\n Erro na alocacao de memoria\n");
	

	printf("Numero do segmento de memoria alocado: %d \n",numero_do_segmento) ;


	soma = (int *) shmat(numero_do_segmento, 0, 0);		//atribui o segmento de memoria 
								//para a var soma

	*soma = 0;					

	pid = fork();

	if (pid == 0) {

		for (i=0;i<TAM/2;i++){
			*soma = *soma + vetor[i];
			//sleep(4);					//analisar o sleep
			printf("\nProcesso filho, Soma = %d\n",*soma);
		}
	} else {

		for (j=TAM/2;j<TAM;j++){
			*soma = *soma + vetor[j];
			//wait(NULL);
			printf("\nProcesso pai,   Soma = %d\n",*soma);
		}
	}
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
                vetor[z] = z; //rand()%1000;
}

