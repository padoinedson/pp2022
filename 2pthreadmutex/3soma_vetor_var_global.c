// as threads somam na var global com concorrencia
 
#include <pthread.h>
#include <stdio.h>
#include "tempo.h"

#define TAM 100000000

//variaveis de escopo global
int 	vetor[TAM];
unsigned long	somaglobal;

void mostra_vetor();
void inicializa_vetor();

void *soma_vetor(void *arg);

int main(int argc, char *argv[])
{
	tempo1();

        pthread_t t1, t2;
        int i, x, y;

	somaglobal = 0;

	inicializa_vetor();

	//mostra_vetor();

	x = 0;	
	pthread_create(&t1, NULL, soma_vetor, (void *)&x);

	y = TAM / 2;	
	pthread_create(&t2, NULL, soma_vetor, (void *)&y);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("\n A soma do vetor  = %lu \n\n\n", somaglobal ); 

	tempo2();
	tempoFinal("mili segundos", argv[0], MSGLOG);
}


void * soma_vetor(void *arg)
{

        int x, pos = *((int*)arg);

	pthread_t pid = pthread_self();

        printf("\n thread inicia na pos = %d ", pos);

        //sleep(5);
        for (x=pos; x < (pos + TAM/2); x ++){
                somaglobal += vetor[x];
		//printf("\nThread %lu - Soma = %d\n", pid, somaglobal);
	}
        return(NULL);
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
                vetor[z] = z;
}

