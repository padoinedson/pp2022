#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include <pthread.h>
#include "tempo.h"

#define TAM 40
int NUMTHREAD = 2;
int status = 0;

void *encontrar(void *arg);

char linha[TAM];

void main(int argc, char *argv[]){

	tempo1();

	pthread_t pidt[NUMTHREAD];
	int inicio[NUMTHREAD + 1];

	inicio[0] = 32;

	int i, tam;
	FILE *fptr;
	if ((fptr = fopen ("password.txt","rb")) == NULL){
		printf ("Nao posso abrir o arquivo");
		exit(1);
	}
							
	fgets(linha,TAM,fptr);
	fclose(fptr);

	tam = strlen (linha);
	printf ("\n\nTamanho da senha %d \n\n", tam);

	for (i = 0; i < NUMTHREAD; i++)
	{
		pthread_create(&pidt[i], NULL, encontrar, (void *)&inicio[i]);
		inicio[i + 1] = inicio[i] + 95 / NUMTHREAD;
//		printf("inicio da thread \n");
	}

	for (i = 0; i < NUMTHREAD; i++)
		pthread_join(pidt[i], NULL);
	
	
	tempo2();
	tempoFinal("mili segundos", argv[0], MSGLOG);

	

	exit(0);
	


}//final do main 

void * encontrar(void*arg){

	int pos = *((int*)arg);
	
	int cont;
	char c, d, e, f, g, h, ii, j;
	char senha[TAM];
	
	cont = 0;																
	int ok = 0;
	while (1) {		

		for (c = pos ; c < (pos+(95/NUMTHREAD)); c++ ){   				//for 1o. char
			senha[0] = c; 

	   		for (d = 32; d < 127; d++){    			//for 2o. char
				senha[1] = d;

		   		for (e = 32; e < 127; e++){    		//for 3o. char
					senha[2] = e;
				
					for (f = 32; f < 127; f++){  	//for 4o. char
						senha[3] = f;

						for (g = 32; g < 127; g++){  	//for 5o. char
							senha[4] = g;

							for (h = 32; h < 127; h++){  	//for 6o. char
								senha[5] = h;

								for (ii = 32; ii < 127; ii++){  	//for 7o. char
									senha[6] = ii;
								
									for (j = 32; j < 127; j++){  	//for 8o. char
										senha[7] = j;						

										cont ++;
				/*						printf("\nteste %d -> %s (%ld) - senha %s (%ld)",
												cont, 
												senha, 
												strlen(senha), 
												linha, 
												strlen(linha)); 
				*/
										ok = strcmp  (senha, linha);

										if (ok == 0){
											printf("\n\n\n\nsenha encontrada: %s",senha);
											printf("\n\n\n\nnúmero de testes: %d\n\n\n",cont);
											
											status = 1;

											return (void *) 0;																				

										}//final do if
									}//8
								}//7					
							}//6
						}//final do for  5o. char						

					}//final do for  4o. char

				}//final do for  3o. char

			}//final do for  2o. char

		}//final do for  1o. char

	}//final do while

	return(0);
}
