
#include "mpi.h"
#include <stdio.h>
#include "tempo.h"

#define L 10
#define C 10


void inicializa_matrizL(int mat[C][L]);
void inicializa_matrizC(int mat[C][L]);
void mostra_matriz(int mat[C][L]);
void zera_matriz(int mat[C][L]);
void multiplica(int mat1[C][L], int mat2[C][L], int mat3[C][L], int ini, int fim);



int main(int argc,char *argv[])
{
	MPI_Status status;
	int myid, numprocs, parte, i, ini;
	double t1 = 0.0, t2   = 0.0;

	int m1[C][L], m2[C][L], m3[C][L];
	
	tempo1();

	MPI_Init(&argc,&argv);

	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	printf("\nNumero total de processos: %d", numprocs);

	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	printf("\nMeu id: %d\n", myid);




	parte = (int)L / numprocs;


	if (myid == 0) /*mestre*/
	{

		inicializa_matrizL(m1);
		inicializa_matrizC(m2);
		zera_matriz(m3);

	        printf("\n  M A T R I Z   m1\n");
		mostra_matriz(m1);
	        printf("\n  M A T R I Z   m2\n");
		mostra_matriz(m2);
	        printf("\n  M A T R I Z   m3\n");
		mostra_matriz(m3);
		
		t1 = MPI_Wtime();

		ini = 0;

		for (i=1; i< numprocs; i++){

			MPI_Send(&ini,     1, MPI_INT, i, 4, MPI_COMM_WORLD);
			MPI_Send(m1,     C*L, MPI_INT, i, 4, MPI_COMM_WORLD);  
			MPI_Send(m2,     C*L, MPI_INT, i, 4, MPI_COMM_WORLD);
//			printf("\n.:mestre:.  envia ini = %d para nodo %d ", ini, i);
			
			ini = ini + parte;

		}

		printf("\n.:mestre:.  calcula ini = %d até %d \n", ini, L);
		multiplica(m1, m2, m3, ini, L);


		mostra_matriz(m3);


		ini = 0;
		for (i=1; i< numprocs; i++){
			MPI_Recv(&m3[ini], parte*L, MPI_INT, i, 4, MPI_COMM_WORLD, &status);

		ini = ini + parte;

		}

 		

		printf("\n============== resultado final ==================\n");
		mostra_matriz(m3);
 

		t2 = MPI_Wtime();

 
		printf("\nTempo de execucao do mestre = %f segundos\n", t2-t1);
		fflush( stdout );


		tempo2();

		tempoFinal("mili segundos", argv[0], MSGLOG);

	} else 
	{ /*escravo*/

		MPI_Recv(&ini,      1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
		MPI_Recv(m1,      C*L, MPI_INT, 0, 4, MPI_COMM_WORLD, &status); 
		MPI_Recv(m2,      C*L, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);

		printf("\n.:slave:. calcula ini = %d até %d \n", ini, ini+parte);

		zera_matriz(m3);
		multiplica(m1, m2, m3, ini, ini+parte);

		mostra_matriz(m3);

		MPI_Send(&m3[ini], parte*L, MPI_INT, 0, 4, MPI_COMM_WORLD);
	}


	MPI_Finalize();

	return 0;
}



void inicializa_matrizL(int mat[C][L])
{
        int z, v;
        printf("\n inicializando matriz ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			mat[z][v] = z+1;
		}
}

void inicializa_matrizC(int mat[C][L])
{
        int z, v;
        printf("\n inicializando matriz ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			mat[z][v] = v+2;
		}
}

void zera_matriz(int mat[C][L])
{
        int z, v;
        printf("\n zerando matriz ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			mat[z][v] = 0;
		}
}

void multiplica(int mat1[C][L], int mat2[C][L], int mat3[C][L], int ini, int fim)
{
	int i, j, v;

        printf("\n  multiplicando m3 = m1 * m2 .... \n");
	for (i = ini; i < fim; i++)
		for (j = 0; j < C; j++){
			for (v = 0; v < C; v++)
				mat3[i][j] = mat3[i][j] + mat1[i][v] * mat2[v][j];
		}
}



void mostra_matriz(int mat[C][L])
{
        int z, v;

        for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf(" %4d", mat[z][v]);
		}
        	printf("\n");
	}
}

void mostra_vetor(int vet[])
{
        int v;
        printf("\n  V E T O R   x \n");

	for (v=0; v < C; v++) {
       	        printf("  %3d", vet[v]);
        	printf("\n");
	}
}

void mostra_resultado(int vet[])
{
	int v;
        printf("\n  V E T O R   b \n");

	for (v=0; v < C; v++) {
       	        printf(" %4d", vet[v]);
        	printf("\n");
	}
	printf("\n\n");
}





