//mpirun -np 2 ex5

//mpirun -np 2 --host Aspire,Aspire ex5


/*
Edson Luiz Padoin

  Mestre:
	inicializa vetor 
	envia para o escravo
  Escravo:
	recebe o vetor do mestre
	faz a soma do vetor
	envia o resultado de volta para o mestre
  Mestre:
	recebe o resultado do escravo
	exibe o numero na tela
*/

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

 


        MPI_Send(vet, TAM, MPI_INT, 1, 4, MPI_COMM_WORLD);

        MPI_Recv(&soma1, 1, MPI_INT, 1, 4, MPI_COMM_WORLD, &status);

        printf("\nSoma = %d \n\n\n\n", soma1);


    }else {/*escravo*/

            int vet[TAM], soma2, i;
            MPI_Recv(vet, TAM, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);

            soma2 = 0;
            for (i = 0; i < TAM; i++)
                 soma2 = soma2 + vet[i];

            MPI_Send(&soma2, 1, MPI_INT, 0, 4, MPI_COMM_WORLD);
    }


    MPI_Finalize();

    return 0;
}



 
 

