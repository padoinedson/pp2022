
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include "tempo.h"

void *funcao(void *arg);


int main(int argc, char *argv[])
{


        pthread_t 	t1;
        int 		x;


	pthread_create(&t1, NULL, funcao, NULL);

	sleep (1);


	pthread_kill(t1, SIGKILL);

        printf("\n pai \n .");
	printf("\nDigite um numero para encerrar o programa\n\n");	
	

}



void * funcao(void *arg)
{
	pthread_t pid = pthread_self();

        printf("\n thread %lu iniciou ", pid);

        for (;;){
	        printf("\n th .");
		sleep(1);
	}
}


