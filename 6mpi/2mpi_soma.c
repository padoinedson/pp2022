/*
Edson Luiz Padoin

  Mestre:
	le dois numeros 
	envia para o escravo
  Escravo:
	recebe os dois numeros do mestre
	faz a soma dos dois numeros
	envia o resultado de volta para o mestre
  Mestre:
	recebe o resultado do escravo
	exibe o numero na tela
*/

#include "mpi.h"
#include <stdio.h>
#include <math.h>

#define DEBUG   0   


int main(int argc,char *argv[])
{

    MPI_Status status;
    int myid, numprocs;


    MPI_Init(&argc,&argv);

    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	printf("\nNumero total de processos: %d", numprocs);

    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	printf("\nMeu id: %d", myid);



    if (myid == 0) /*mestre*/
    {

        int n, m, sum1; 
        printf("\nDigite m:");
        scanf("%d",&m);

        printf("\nDigite n:");
        scanf("%d",&n);


        		 //var qtde tipo dest etiq
        MPI_Send(&m, 1, MPI_INT, 1, 4, MPI_COMM_WORLD);
        MPI_Send(&n, 1, MPI_INT, 1, 4, MPI_COMM_WORLD);

        MPI_Recv(&sum1, 1, MPI_INT, 1, 4, MPI_COMM_WORLD, &status);

        printf("\nSoma = %d \n \n ", sum1);



	
	
    }else {/*escravo*/

            int sum2, a, b;

            MPI_Recv(&a, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
            MPI_Recv(&b, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
                    printf("\nSlave - Vlrs recebidos a = %d b = %d \n \n ", a, b);

            sum2 = a + b;

            MPI_Send(&sum2, 1, MPI_INT, 0, 4, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}




