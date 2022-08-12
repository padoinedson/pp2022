#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int vetor[TAM];
int soma;

void inicializa_vetor();
void mostra_vetor();
void *somaVET(void *arg);             //funcao que sera executada pela thread	


int main()
{
        
    pthread_t t1, t2;
    int x,y;

	inicializa_vetor();

	mostra_vetor();

    soma = 0;
	x = 0;	
	pthread_create(&t1, NULL, somaVET, (void *)&x);

	y = 5;	
	pthread_create(&t2, NULL, somaVET, (void *)&y);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL); 

	printf("\n\n Soma %d \n\n", soma);

	pthread_exit(NULL);

}


void * somaVET(void *arg)
{

        int x, pos = *((int*)arg);

        printf("\n thread inicia na pos = %d ", pos);
	
        for (x=pos; x < (TAM/2+pos); x ++){
	        soma += vetor[x];
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
                vetor[z] = rand()%10;
}

