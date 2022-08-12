//criar dinamicamente várias threads
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int vetor[TAM];
int maiorglobal;
void mostra_vetor();
void *maior(void *arg);
void inicializa_vetor();

int NUMTHREAD;

int main(int argc, char *argv[])
{

	NUMTHREAD = atoi(argv[1]);

	if (NUMTHREAD < 1)
	{
		printf("Digite ./nome do executavel + numero de thread");
		return 0;
	}

	pthread_t pidt[NUMTHREAD];
	int x, y, inicio[NUMTHREAD + 1];

	inicializa_vetor();

	mostra_vetor();

	inicio[0] = 0;

	int i;
	for (i = 0; i < NUMTHREAD; i++)
	{
		pthread_create(&pidt[i], NULL, maior, (void *)&inicio[i]);
		inicio[i + 1] = inicio[i] + TAM / NUMTHREAD;
	}

	for (i = 0; i < NUMTHREAD; i++)
		pthread_join(pidt[i], NULL);

	printf("\n Maior global %d\n\n ", maiorglobal);
}

void *maior(void *arg)
{

	int x, m, pos = *((int *)arg);

	printf("\n thread inicia na pos = %d ", pos);

	for (x = pos; x < (TAM / NUMTHREAD + pos); x++)
	{
		if (vetor[x] > m)
			m = vetor[x];
	}
	if (maiorglobal < m)
		maiorglobal = m;
	printf("\n Maior local %d\n\n ", m);

	scanf("%d", &m);

	return (NULL);
}

void mostra_vetor()
{
	int z;
	printf("\n v e t o r \n");
	for (z = 0; z < 10; z++)
	{
		printf("\n Posicao %d - valor %d", z, vetor[z]);
	}
	printf("\n\n\n");
}

void inicializa_vetor()
{
	int z;
	printf("\n inicializando vetor ...\n");
	for (z = 0; z < TAM; z++)
		vetor[z] = rand() % 1000;
}
