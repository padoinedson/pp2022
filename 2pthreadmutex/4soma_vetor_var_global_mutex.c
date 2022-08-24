// as th fazem as somas em uma var global com mutex

#include <pthread.h>
#include <stdio.h>
#include "tempo.h"

#define TAM 100000000

//variaveis de escopo global
int 	vetor[TAM];
unsigned long	somaglobal;
pthread_mutex_t m;

void inicializa_vetor();
void mostra_vetor();
void *soma_vetor(void *arg);


int main(int argc, char *argv[])
{

	tempo1();

        pthread_t 	t1, t2;
        int 		x, y;

	inicializa_vetor();

	//mostra_vetor();
	
	pthread_mutex_init(&m,NULL);
	somaglobal = 0;

	x = 0;	
	pthread_create(&t1, NULL, soma_vetor, (void *)&x);

	y = TAM / 2;	
	pthread_create(&t2, NULL, soma_vetor, (void *)&y);


	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

        printf("\n Soma total == %lu \n\n", somaglobal);

	tempo2();
	tempoFinal("mili segundos", argv[0], MSGLOG); 
}



void * soma_vetor(void *arg)
{
	int x, pos = *((int*)arg);

	pthread_t pid = pthread_self();

        printf("\n thread inicia na pos = %d ", pos);
       // sleep(5);

        for (x=pos; x < (pos+TAM/2); x ++){

		pthread_mutex_lock(&m);
                   somaglobal += vetor[x];
		pthread_mutex_unlock(&m);

		//printf("\nThread %lu - Soma = %d\n", pid, somaglobal);
	}
	pthread_exit(NULL);
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




