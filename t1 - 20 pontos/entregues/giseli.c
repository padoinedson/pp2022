#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "tempo.h"
#include <math.h>


int inicio = 32,fim = 127, NUMTHREAD, QUANTIDADEPORTHREAD;
void *crash(void *arg);
pthread_t *pidt;
void main(int argc, char *argv[]){
    tempo1();
    NUMTHREAD = atoi(argv[1]);

    double qt = (((double)fim) - (double)inicio) / (double)NUMTHREAD;
    QUANTIDADEPORTHREAD = round(qt);

    int inicioT[NUMTHREAD + 1];
    pidt = malloc(sizeof(pthread_t) * NUMTHREAD);

    inicioT[0] = 32;
    
    for (int i = 0; i < NUMTHREAD; i++){
        pthread_create(&pidt[i], NULL, crash, (void *)&inicioT[i]);
        inicioT[i + 1] = inicioT[i] + QUANTIDADEPORTHREAD;
    }

    for (int i = 0; i < NUMTHREAD; i++){
        pthread_join(pidt[i], NULL);
    }    
}

void *crash(void *arg){
    char linha[40], senha[40];
    FILE *fptr;

    if ((fptr = fopen("password.txt", "rb")) == NULL){
        printf("Nao posso abrir o arquivo");
        exit(1);
    }

    fgets(linha, 40, fptr);
    fclose(fptr);
    int qauntidadeTeste = 0, ok = 0;
    int quantidadeThreads = NUMTHREAD;
    int comeco = *((int *)arg);
    int ultimo = comeco + QUANTIDADEPORTHREAD;
    
    if (ultimo > fim){
        ultimo = fim;
    }
    
    for (int c = comeco; c < ultimo; c++){
        senha[0] = c;
        for (int d = 32; d < 127; d++){
            senha[1] = d;
            for (int e = 32; e < 127; e++){
                senha[2] = e;
                for (int f = 32; f < 127; f++){
                    senha[3] = f;
                    for (int g = 32; g < 127; g++){
                        senha[4] = g;
                        for (int h = 32; h < 127; h++){
                            senha[5] = h;
                            qauntidadeTeste++;
                            ok = strcmp(senha, linha);
                            if (ok == 0){
                                printf("\n\nsenha encontrada: %s", senha);
                                printf("\nnúmero de testes: %d\n\n", qauntidadeTeste);
                                tempo2();
                                tempoFinal("segundos", "", MSGLOG);
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
}