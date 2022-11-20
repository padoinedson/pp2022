


#include "mpi.h"
#include <stdio.h>
 

int main(int argc,char *argv[])
{


    MPI_Init(&argc,&argv);


    int numprocs;
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    printf("\nNumero total de processos: %d", numprocs);


    int myid;
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    printf("\nMeu id: %d\n", myid);


    if (myid == 0) /*mestre*/
    {
 
			printf("\n\nMestre rodando id: %d \n\n", myid);


    }else {/*escravo*/

			printf("\n\nEscravo rodando id: %d \n\n", myid);

    }


    MPI_Finalize();

    return 0;
}




