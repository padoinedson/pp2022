//mpirun -np 2 ex5

//mpirun -np 2 --host Aspire,Aspire ex5




#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAM 10


int main(int argc,char *argv[])
{


    MPI_Status status;
    int myid, numprocs;


    MPI_Init(&argc,&argv);

    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    printf("\nNumero total de processos: %d", numprocs);

    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    printf("\nMeu id: %d", myid);





	printf("\nInicializar vetor");
	
    if (myid == 0) /*mestre*/
    {

        int vet[TAM], i, z, soma1;

        for (i = 0; i < TAM; i++){
            vet[i] = rand()% 100;
        }


        printf("\n v e t o r: [ ");
        for (z=0; z < TAM; z ++){
                printf("  %d ", vet[z]);
        }
        printf("] \n \n\n");

 


        MPI_Send(vet, TAM, MPI_INT, 1, 10, MPI_COMM_WORLD);

        MPI_Recv(vet, TAM, MPI_INT, 1, 20, MPI_COMM_WORLD, &status);

        printf("\n v e t o r: [ ");
        for (z=0; z < TAM; z ++){
                printf("  %d ", vet[z]);
        }
        printf("] \n \n\n");


    }else {/*escravo*/

            int vet2[TAM], i;
            MPI_Recv(vet2, TAM, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);

 
            for (i = 0; i < TAM; i++)
                 vet2[i] = vet2[i] + 1;

            MPI_Send(vet2, TAM, MPI_INT, 0, 20, MPI_COMM_WORLD);
    }


    MPI_Finalize();

    return 0;
}



 
 

