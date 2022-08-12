
#include <pthread.h>
#include <stdio.h>
#include  <stdlib.h>

#define NUMTHREAD 5000

int x;	
void *add(void *arg);             

pthread_mutex_t m;              //var de mutex


int main(int argc,char *argv[])
{

	pthread_t  pidt[NUMTHREAD];
	
	pthread_mutex_init(&m,NULL);              //inicializa o mutex

	int i;
	for (i=0; i < NUMTHREAD; i ++){
		pthread_create(&pidt[i], NULL, add, (void *)&i);
	}


	for (i=0; i < NUMTHREAD; i ++)     
		pthread_join(pidt[i], NULL);
	
	printf ("valor de x fora das threads = %d \n", x);
	
}


void * add(void *arg)
{

        int p = *((int*)arg);

		pthread_mutex_lock(&m);         //fecha
            x ++;
		pthread_mutex_unlock(&m);       //abre

		printf ("x = %d \n", x);

        return(NULL);
}




