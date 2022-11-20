

//mpirun -np 2 --host Aspire,Aspire ex5


#include "mpi.h"
#include <stdio.h>


int main(int argc,char *argv[])
{

    MPI_Status status;
    int  myid, numprocs;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
 

    if (myid == 0) 
    {

    		int  m, i;
			printf("\nNumero total de processos: %d\n\n", numprocs);
		 
			//mestre 0 envia para todos (1 ate n-1) escravos em ordem de i 
			for (i=1; i < numprocs; i++)
					MPI_Send(&i, 1, MPI_INT, i, 4, MPI_COMM_WORLD);


			//mestre recebe de todos os escravos em qualquer ordem
			for (i=1; i < numprocs; i++){
				MPI_Recv(&m, 1, MPI_INT, MPI_ANY_SOURCE, 4, MPI_COMM_WORLD, &status);
					printf("mestre recebeu = %d  do slave %d\n", m, status.MPI_SOURCE);
			}

    }else{

    		int  x;
            MPI_Recv(&x, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
			printf("slave %d recebeu = %d\n",  myid, x);

            MPI_Send(&myid, 1, MPI_INT, 0, 4, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
