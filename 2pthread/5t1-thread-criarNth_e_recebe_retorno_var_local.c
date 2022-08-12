
//exemplo de como criar dinamicamente várias threads
//e receber o retorno de todas elas
//para executar digite ./5d 4 


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tempo.h"

#define TAM 100

//variaveis de escopo global
int 	vetor[TAM], parte;

void inicializa_vetor();
void mostra_vetor();
void *soma_vetor(void *arg);


int main(int argc, char *argv[])
{
	tempo1();

    pthread_t 	t_id[20];
   // pthread_barrier_t mybarrier;
	
    
    int 		i, j, aux, soma, num_thread, ini[20];

	num_thread = atoi(argv[1]);
	printf("\nSerão criadas %d thread.\n", num_thread);


	//pthread_barrier_init(&mybarrier, NULL, num_thread);


	parte = (int) TAM / num_thread;

	inicializa_vetor();

//	mostra_vetor();
	
//criacao da threads
	ini[0]=0;
	for (i=0; i< num_thread; i++){
		pthread_create(&t_id[i], NULL, soma_vetor, (void *)&ini[i]);
		printf("\n.:thread %d criada para rodar a partir da posição = %d ", i, ini[i]);
		ini[i+1] = ini[i] + parte;

	}


	//pthread_barrier_wait(&mybarrier);


//uniao da threads
	soma = 0;
	for (j=0; j< num_thread; j++){
		pthread_join(t_id[j], (void **)&aux);
		printf("\n j = %d -- aux = %d \n\n", j, aux);
		soma += aux;
	}

    printf("\n Soma total = %d \n\n", soma);

	tempo2();
	tempoFinal("mili segundos", argv[0], MSGLOG);
	
	
	//pthread_barrier_destroy(&mybarrier);
	  
}



void * soma_vetor(void *arg)
{
	int x, pos = *((int*)arg);
	int somalocal = 0;

	pthread_t pid = pthread_self();

    printf("\n thread inicia na pos = %d ", pos);

    for (x=pos; x < (pos+parte); x ++)
          somalocal += vetor[x];

	printf("\n Thread %lu - SomaLocal =   %d \n", pid, somalocal);
 
	pthread_exit((void *)somalocal);
}





void mostra_vetor()
{
        int z;
        printf("\n  v e t o r \n");
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
                vetor[z] = z;
}




