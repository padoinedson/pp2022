#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include <pthread.h>    
#include "tempo.h"


#define NUMTHREAD 8

char linha[40], senha[40], c, d, e, f, g, h, k, j;
int cont, ok, i, pos, a, tam, inicio[NUMTHREAD + 1];
char * args; 
void *repeticao(void *arg);

void main(int argc, char *argv[]){

    tempo1();
    args = argv[0];

    FILE *fptr;

    if ((fptr = fopen ("password.txt","rb")) == NULL){
        printf ("Nao foi possivel abrir o arquivo");
        exit(1);
    }

    fgets(linha,40,fptr);
    fclose(fptr);

    tam = strlen (linha);

    pthread_t pidt[NUMTHREAD];

    ok = 0; cont = 0; pos = 0;

    inicio[0] = 32; 

    int i;  
    for (i = 0; i < NUMTHREAD; i++){
        pthread_create(&pidt[i], NULL, repeticao, (void *)&inicio[i]);
        inicio[i+1] = inicio[i] + (95 / NUMTHREAD);
    }

    for (i = 0; i < NUMTHREAD; i++){
        pthread_join(pidt[i], NULL);
    }

} 

void * repeticao(void *arg){
    
    int inicio = *((int*)arg);
    while(1){
            for (c = inicio; c < inicio + (95/NUMTHREAD); c++){                 
            senha[0] = c; 

            for (d = 32; d < 127; d++){             
                senha[1] = d;

                for (e = 32; e < 127; e++){         
                    senha[2] = e;
                
                    for (f = 32; f < 127; f++){     
                        senha[3] = f;
                        
                        for (g = 32; g < 127; g++){     
                        senha[4] = g;
                        
                       	 for (h = 32; h < 127; h++){     
                             senha[5] = h;
                             
                             for (k = 32; k < 127; k++){     
                             senha[6] = k;
                             
                             for (j = 32; j < 127; j++){     
                             senha[7] = j;
                             
                             cont ++;

                        printf("\n inicio %i teste %d -> %s (%ld) - senha %s (%ld)",
                                inicio,
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
                            tempoFinal("segundos", args, MSGLOG);

                            exit(0);
                        }

                    }

                }

            }

        }
    }
}
}	
}
}
}
