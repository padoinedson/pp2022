#include <pthread.h>
#include <stdio.h>


//funcao que sera executada na thread	
void *funcao_teste(void *arg);			 

//variavel de escopo global
int y;


							
int main()
{

    pthread_t 	tid1, tid2;                   //var q armazena o numero da thread

    int x = 0;
    y = 5000;				
					
	pthread_create(&tid1, NULL, funcao_teste, (void *)&x); 
	pthread_join(tid1, NULL);
    printf("\n y = %d ", y);

	pthread_create(&tid2, NULL, funcao_teste, (void *)&x); 
	pthread_join(tid2, NULL);
    printf("\n y = %d \n\n", y);

}



void * funcao_teste(void *arg)
{

    y ++;

    printf("\n y na thread = %d ", y);

}


