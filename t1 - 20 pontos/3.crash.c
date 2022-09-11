#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include "tempo.h"

char linha[40], senha[40];

void main(int argc, char *argv[]){

	tempo1();

	FILE *fptr;
	int cont, ok, i, pos, a, tam;
	char c, d, e, f;

	if ((fptr = fopen ("password.txt","rb")) == NULL){
		printf ("Nao posso abrir o arquivo");
		exit(1);
	}

	fgets(linha,40,fptr);
	fclose(fptr);


	tam = strlen (linha);
	printf ("\n\nTamanho da senha %d \n\n", tam);

	ok = 0; cont = 0; pos = 0;

	while (1) {

		for (c = 32; c < 127; c++){   				//for 1o. char
			senha[0] = c; 

	   		for (d = 32; d < 127; d++){    			//for 2o. char
				senha[1] = d;

		   		for (e = 32; e < 127; e++){    		//for 3o. char
					senha[2] = e;
				
					for (f = 32; f < 127; f++){  	//for 4o. char
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

							tempo2();
							tempoFinal("segundos", argv[0], MSGLOG);

							exit(0);
						}//final do if

					}//final do for  4o. char

				}//final do for  3o. char

			}//final do for  2o. char

		}//final do for  1o. char

	}//final do while

}//final do main 

