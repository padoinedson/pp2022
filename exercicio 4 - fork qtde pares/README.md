
# Programação Paralela

## Exercício 4


#### Sprint 1


Implementar um programa utilizando o compilador gcc que:

- criar um vetor de 1.000 posições;

- inicializá-lo com números aleatórios;

- criar 2 processos utilizando <<<fork>>>;

- encontrar a qtde de números pares do vetor;

- entregar no "https://github.com/padoinedson/pp2022/exercicio4" em um arquivo com nome `ex4-seunome.c`

- Dicas:  
	#include <stdlib.h>    
    srandom(time(NULL));  
	rand() % 1000;  

