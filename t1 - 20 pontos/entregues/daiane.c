#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "tempo.h"

int TAMANHO, NUMTHREAD, QTDPORTHREAD;
void * nThread(void * arg);

void main(int argc, char * argv[]) {

  tempo1();

  NUMTHREAD = atoi(argv[1]);
  TAMANHO = 127 - 32;
  QTDPORTHREAD = TAMANHO / NUMTHREAD;

  pthread_t pidt[NUMTHREAD];
  int inicioThread[NUMTHREAD + 1];

  inicioThread[0] = 32;

  for (int i = 0; i < NUMTHREAD; i++) {
    pthread_create( & pidt[i], NULL, nThread, (void * ) & inicioThread[i]);
    inicioThread[i + 1] = inicioThread[i] + QTDPORTHREAD;
  }

  for (int i = 0; i < NUMTHREAD; i++) {
    pthread_join(pidt[i], NULL);
  }

}

void * nThread(void * arg) {

  char linha[40], senha[40];
  FILE * fptr;

  if ((fptr = fopen("password.txt", "rb")) == NULL) {
    printf("Nao posso abrir o arquivo");
    exit(1);
  }

  fgets(linha, 40, fptr);
  fclose(fptr);
  int cont = 0, ok = 0;

  int comeco = * ((int * ) arg);

  TAMANHO = strlen(linha);

  printf("\nTamanho da senha %d \n ", TAMANHO);

  while (1) {

    for (int a = comeco; a < (comeco + QTDPORTHREAD); a++) {
      senha[0] = a;

      for (int b = 32; b < 127; b++) {
        senha[1] = b;

        for (int c = 32; c < 127; c++) {
          senha[2] = c;

          for (int d = 32; d < 127; d++) {
            senha[3] = d;

           for (int e = 32; e < 127; e++) {
              senha[4] = e;

               for (int f = 32; f < 127; f++) {
                senha[5] = f;

                for (int g = 32; g < 127; g++) {
                  senha[6] = g;

                  for (int h = 32; h < 127; h++){
                    senha[7] = h; 

                    cont++;
                    printf("\nteste %d -> %s (%ld) - senha %s (%ld)",
                            cont, 
                            senha, 
                            strlen(senha), 
                            linha, 
                            strlen(linha));

                    ok = strcmp(senha, linha);

                    if (ok == 0) {
                      printf("\n\n\n\nsenha encontrada: %s", senha);
                      printf("\n\n\n\nnúmero de testes: %d\n", cont);

                      exit(0);
                      
                      tempo2();
                      tempoFinal("segundos", "", MSGLOG);
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
