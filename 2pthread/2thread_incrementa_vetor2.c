#include <pthread.h>
#include <stdio.h>

#define TAM 10000

int vetor[TAM];

void inicializa_vetor();
void mostra_vetor();

void *incrementa(void *arg);             //funcao que sera executada pela thread	


int main()
{
        pthread_t t1, t2, t3, t4;
        int x,y,z,w;

	inicializa_vetor();

	mostra_vetor();

	x = 0;	
	pthread_create(&t1, NULL, incrementa, (void *)&x);

	y = 2500;	
	pthread_create(&t2, NULL, incrementa, (void *)&y);

        z = 5000;  
        pthread_create(&t3, NULL, incrementa, (void *)&z);

        w = 7500;  
        pthread_create(&t4, NULL, incrementa, (void *)&w);


	pthread_join(t1, NULL);
	pthread_join(t2, NULL); 
        pthread_join(t3, NULL);
        pthread_join(t4, NULL);

	mostra_vetor();

	pthread_exit(NULL);

}


void * incrementa(void *arg)
{

        int x, pos = *((int*)arg);

        printf("\n thread inicia na pos = %d ", pos);
	
        for (x=pos; x < (2500+pos); x ++){
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
