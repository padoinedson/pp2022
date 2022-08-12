#include <pthread.h>
#include <stdio.h>

#define TAM 10

int vetor[TAM];

void inicializa_vetor();
void mostra_vetor();

void *incrementa(void *arg);             //funcao que sera executada pela thread	


int main()
{
        pthread_t t1, t2;
        int x,y;

	inicializa_vetor();

	mostra_vetor();

	x = 0;	
	pthread_create(&t1, NULL, incrementa, (void *)&x);

	y = 5;	
	pthread_create(&t2, NULL, incrementa, (void *)&y);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL); 

	mostra_vetor();

	pthread_exit(NULL);

}


void * incrementa(void *arg)
{

        int x, pos = *((int*)arg);

        printf("\n thread inicia na pos = %d ", pos);
	
        for (x=pos; x < (5+pos); x ++){
	        vetor[x] += 10000;
		//sleep(10);
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






//executar sem o join(!!!)
