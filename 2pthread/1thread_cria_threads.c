#include <pthread.h>
#include <stdio.h>


//funcao que sera executada na thread	
void *funcao_teste(void *arg);			 


							
int main()
{

    pthread_t 	tid1;                   //var q armazena o numero da thread

    int 		x = 1000;				
					
	pthread_create(&tid1, NULL, funcao_teste, (void *)&x); 
  
	pthread_join(tid1, NULL);

}



void * funcao_teste(void *arg)
{

	pthread_t pid = pthread_self();			//funcao retorna num da thread
    printf("\n Thread numero %lu criada \n", pid);



	int  *argumento1 = (int*)arg;              //com uso de ponteiros
    printf("\n thread recebeu o argumento = %d ", *argumento1);

    int  argumento2 = *((int*)arg);            //sem uso de ponteiros
    printf("\n thread recebeu o argumento = %d ",  argumento2);



    printf("\n\n Thread numero %lu finalizada \n", pid);

    return(NULL);
}


