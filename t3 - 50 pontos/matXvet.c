 
#include <stdio.h>


#define L 3 
#define C L

int A[C][L], x[C], b[L];

void inicializa_matriz();
void mostra_matriz();
void multiplica();
void mostra_resultado();

int main(int argc, char *argv[])
{


	inicializa_matriz();

 	mostra_matriz();

	multiplica();

 	mostra_resultado();


}


void multiplica()

{	
	int i, j;

        printf("\n  multiplicando.... \n");
	for (i = 0; i < L; i++)
		for (j = 0; j < C; j++)
			b[i] = b[i] + A[i][j] * x[j];
}




void mostra_matriz()
{
        int z, v;
        printf("\n  M A T R I Z  A \n");

        for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf(" %3d", A[z][v]);
		}
        	printf("\n");
	}

        printf("\n  V E T O R   x \n");

	for (v=0; v < C; v++) {
       	        printf("  %3d", x[v]);
        	printf("\n");
	}
}

void mostra_resultado()
{
	int v;
        printf("\n  V E T O R   b \n");

	for (v=0; v < C; v++) {
       	        printf(" %4d", b[v]);
        	printf("\n");
	}
	printf("\n\n");
}

void inicializa_matriz()
{
        int z, v;
        printf("\n inicializando matriz ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			A[z][v] = z+1;
			x[v]    = v+1;
			b[v]    = 0;
		}
}



