#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tempo.h"

int INICIO = 32, FIM = 127, NUMTHREAD, QUANTIDADEPORTHREAD;
void *tentar(void *arg);
pthread_t *pidt;
void main(int argc, char *argv[])
{
    tempo1();
    NUMTHREAD = atoi(argv[1]);

    double qt = (((double)FIM - (double)INICIO) / (double)NUMTHREAD);
    QUANTIDADEPORTHREAD = round(qt);

    int inicioThread[NUMTHREAD + 1];
    pidt = malloc(sizeof(pthread_t) * NUMTHREAD);

    inicioThread[0] = 32;
    for (int i = 0; i < NUMTHREAD; i++)
    {
        pthread_create(&pidt[i], NULL, tentar, (void *)&inicioThread[i]);
        inicioThread[i + 1] = inicioThread[i] + QUANTIDADEPORTHREAD;
    }

    for (int i = 0; i < NUMTHREAD; i++)
    {
        pthread_join(pidt[i], NULL);
    }
}

void *tentar(void *arg)
{
    char linha[40], senha[40];
    FILE *fptr;

    if ((fptr = fopen("password.txt", "rb")) == NULL)
    {
        printf("Nao posso abrir o arquivo");
        exit(1);
    }

    fgets(linha, 40, fptr);
    fclose(fptr);
    int cont = 0, ok = 0;
    int quantidadeThreads = NUMTHREAD;
    int comeco = *((int *)arg);
    int ultimo = comeco + QUANTIDADEPORTHREAD;
    if (ultimo > FIM)
    {
        ultimo = FIM;
    }
    printf("\ntentativa começando em %i indo até o %i \n", (comeco), (ultimo));
    for (int c = comeco; c < ultimo; c++)
    {
        senha[0] = c;
        // printf("\navançou um\n");
        for (int d = 32; d < 127; d++)
        {
            senha[1] = d;
            for (int e = 32; e < 127; e++)
            {
                senha[2] = e;
                for (int f = 32; f < 127; f++)
                {
                    senha[3] = f;

                    for (int g = 32; g < 127; g++)
                    {
                        senha[4] = g;
                        for (int h = 32; h < 127; h++)
                        {
                            senha[5] = h;
                            for (int i = 32; i < 127; i++)
                            {
                                senha[6] = i;
                                for (int j = 32; j < 127; j++)
                                {
                                    senha[7] = j;
                                    cont++;
                                    // printf("\nteste %d -> %s (%ld) - senha %s (%ld)", cont, senha, strlen(senha), linha, strlen(linha));
                                    ok = strcmp(senha, linha);
                                    if (ok == 0)
                                    {
                                        printf("\n\nsenha encontrada: %s", senha);
                                        printf("\nnúmero de testes: %d\n\n", cont);
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
    }
}
