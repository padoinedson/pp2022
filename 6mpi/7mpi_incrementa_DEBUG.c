/*
Edson Luiz Padoin

use "-D DEBUG" na compilacao para ver as mensagens do programa
mpicc 2-incrementa2.c -o 2-incrementa -D DEBUG


*/

#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
    MPI_Status status;
    int n, m, a, b, myid, numprocs, namelen, i;
    double mypi, pi, h, sum, x;
    double startwtime = 0.0,
           endwtime   = 0.0;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc,&argv);

    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	#ifdef DEBUG
	printf("\nNumero total de processos: %d", numprocs);
	#endif

    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	#ifdef DEBUG
	printf("\nMeu id: %d", myid);
	#endif

    MPI_Get_processor_name(processor_name,&namelen);
	#ifdef DEBUG
    	printf("\nNome da Maquina : %s\n", processor_name);
	#endif

    if (myid == 0) /*mestre*/
    {
        printf("\nDigite n:");
        scanf("%d",&n);

	startwtime = MPI_Wtime();


	for (i=1; i< numprocs; i++){
	        MPI_Send(&n, 1, MPI_INT, i, 4, MPI_COMM_WORLD);
	        printf("\n.:mestre:.  envia %d para nodo %d ", n, i);
	}
	for (i=1; i< numprocs; i++){
        	MPI_Recv(&m, 1, MPI_INT, i, 4, MPI_COMM_WORLD, &status);
	        printf("\n.:mestre:.  recebe valor %d do nodo %d", m, i);
	}

	endwtime = MPI_Wtime();
	printf("\n\nTempo de execucao = %f\n", endwtime-startwtime);
	fflush( stdout );

    }else {/*escravo*/

            MPI_Recv(&a, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
	        //printf("\n.:escravo:.  recebe %d para nodo mestre\n", a );
            b = a+1;

            MPI_Send(&b, 1, MPI_INT, 0, 4, MPI_COMM_WORLD);
	        //printf("\n.:escravo:.  envia %d para nodo mestre\n", b);
    }


    MPI_Finalize();

    return 0;
}


