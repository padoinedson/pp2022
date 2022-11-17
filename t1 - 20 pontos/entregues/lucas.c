#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "tempo.h"

#define NUMTHREAD 6

char linha[40];
int cont, ok, inicio[NUMTHREAD + 1];
char *argumento;
void *loops(void *arg);

void main(int argc, char *argv[])
{

    tempo1();
    argumento = argv[0];

    FILE *fptr;

    if ((fptr = fopen("password.txt", "rb")) == NULL)
    {
        printf("Nao posso abrir o arquivo");
        exit(1);
    }

    fgets(linha, 40, fptr);
    fclose(fptr);

    printf("\n\nNumero de threads: %d", NUMTHREAD);
    printf("\nSenha a ser encontrada: %s\n\n", linha);

    pthread_t pidt[NUMTHREAD];

    ok = 0;
    cont = 0;

    inicio[0] = 32;

    int index;
    for (index = 0; index < NUMTHREAD; index++)
    {
        pthread_create(&pidt[index], NULL, loops, (void *)&inicio[index]);
        inicio[index + 1] = inicio[index] + (95 / NUMTHREAD);
    }

    for (index = 0; index < NUMTHREAD; index++)
    {
        pthread_join(pidt[index], NULL);
    }
}

void *loops(void *arg)
{

    char senha[40], a, b, c, d, e, f, g, h;
    int inicio = *((int *)arg);
    printf("\nde:%d ate %d", inicio, (inicio + (95 / NUMTHREAD)) - 1);
    while (1)
    {
        for (a = inicio; a < inicio + (95 / NUMTHREAD); a++)
        {
            senha[0] = a;

            for (b = 32; b < 127; b++)
            {
                senha[1] = b;

                for (c = 32; c < 127; c++)
                {
                    senha[2] = c;

                    for (d = 32; d < 127; d++)
                    {
                        senha[3] = d;
                        for (e = 32; e < 127; e++)
                        {
                            senha[4] = e;
                            for (f = 32; f < 127; f++)
                            {
                                senha[5] = f;

                                cont++;
                                ok = strcmp(senha, linha);

                                if (ok == 0)
                                {
                                    printf("\nsenha encontrada: %s", senha);
                                    printf("\nnúmero de testes: %d\n\n\n", cont);

                                    tempo2();
                                    tempoFinal("segundos", argumento, MSGLOG);

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
