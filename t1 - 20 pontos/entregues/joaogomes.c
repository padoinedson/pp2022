#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "tempo.h"

char linha[40], senha[40];
int NUMTHREAD;
int cont, ok, i, pos, a, tam, j;
char c, d, e, f;
int parte;

void *nThread(void *arg){

	int tid = *((int *)arg);
	printf("%d: Olá\n", tid);
    FILE *fptr;

	if ((fptr = fopen ("password.txt","rb")) == NULL){
		printf ("Nao posso abrir o arquivo");
		exit(1);
	}

	fgets(linha,40,fptr);
	fclose(fptr);

	tam = strlen (linha);
	printf ("\n\nTamanho da senha %d \n\n", tam);

    int ok = 0; cont = 0; pos = 0;

	while (1) {
		for (c = tid; c < tid + parte; c++){
			senha[0] = c; 
	   			for (d = 32; d < 127; d++){
					senha[1] = d;
		   			for (e = 32; e < 127; e++){    		
						senha[2] = e;
						for (f = 32; f < 127; f++){  	
							senha[3] = f;
								cont ++;

						printf("\nteste %d -> %s (%ld) - senha %s (%ld)",
								cont, 
								senha, 
								strlen(senha), 
								linha, 
								strlen(linha)); 
                        
						ok = strcmp  (senha, linha);

						if (ok == 0){
							printf("\n\n\n\nsenha encontrada: %s",senha);
							printf("\n\n\n\nnúmero de testes: %d\n\n\n",cont);
							exit(0);
						}
					}
				}
			}
		}
	}


	return(NULL);
}

void main(int argc, char *argv[]){

	tempo1();

	NUMTHREAD = atoi(argv[1]);

	pthread_t pidt[NUMTHREAD];
	int x, y, inicio[NUMTHREAD + 1];

	inicio[0] = 32;
    
    tam = 127 - 32;
    parte = tam / NUMTHREAD;     

	for (j = 0; j < NUMTHREAD; j++)
	{
		pthread_create(&pidt[j], NULL, nThread, (void *)&inicio[j]);
		inicio[j + 1] = inicio[j] + parte;
	}

	for (j = 0; j < NUMTHREAD; j++)
		pthread_join(pidt[j], NULL);
    
    tempo2();
	tempoFinal("segundos", argv[0], MSGLOG);

}