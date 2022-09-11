#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

void grava();
void le();
void testa();

void main(){

	int op;

	while(1){
		printf ("\nDigite: ");
		printf ("\n 1 - para criar a senha");
		printf ("\n 2 - para exibir a senha");
		printf ("\n 3 - para testar a senha");
		printf ("\n 4 - para sair\n");
	
		scanf ("%d", &op);

		switch(op) {
			case 1 : grava(); break;
			case 2 : le(); break;
			case 3 : testa(); break;
			case 4 : exit(1);
			default  : printf ("Funcao Invalida");
		}
	}
}

void grava()
{
	FILE *fptr;
	char linha[40];

	if ((fptr = fopen ("password.txt","wb")) == NULL){
		printf ("Nao posso abrir o arquivo");
		exit(1);
	}

	printf ("Digite a senha\n");
	scanf("%s",linha);
	fputs (linha, fptr);

	fclose(fptr);
	printf("senha gravada\n");
}

void le(){

	FILE *fptr;
	char linha[40];

	if ((fptr = fopen ("password.txt","rb")) == NULL){
		printf ("Nao posso abrir o arquivo");
		exit(1);
	}

	fgets(linha,40,fptr);
	printf ("senha: %s\n", linha);
	fclose(fptr);
}

void testa(){

	FILE *fptr;
	char linha[40], senha[40];
	int ok;

	if ((fptr = fopen ("password.txt","rb")) == NULL){
		printf ("Nao posso abrir o arquivo");
		exit(1);
	}

	fgets(linha,40,fptr);
	fclose(fptr);

	printf ("Digite a senha\n");
	scanf("%s",senha);

	ok = strcmp  (senha, linha);

	if (ok ==0)
		printf("senha correta\n\n");
	else
		printf("senha incorreta\n\n");
}
