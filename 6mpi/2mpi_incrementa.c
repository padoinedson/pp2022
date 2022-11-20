/*
Edson Luiz Padoin

mpirun -np 2 nome
  Mestre:
	le um numero
	envia para o escravo
  Escravo:
	recebe o numero do mestre
	incrementa
	envia o resultado de volta para o mestre
  Mestre:
	recebe o resultado do escravo
	exibe o numero na tela
*/

#include "mpi.h"
#include <stdio.h>
 

int main(int argc,char *argv[])
{
    MPI_Status status;
    int myid, numprocs;
 
  

    MPI_Init(&argc,&argv);

    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    printf("\nNumero total de processos: %d", numprocs);

    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    printf("\nMeu id: %d\n", myid);



    if (myid == 0) /*mestre*/
    {
            int n, m;
			printf("\n\nDigite n:");
			scanf("%d",&n);

            
			MPI_Send(&n, 1, MPI_INT, 1, 4, MPI_COMM_WORLD);

			MPI_Recv(&m, 1, MPI_INT, 1, 123, MPI_COMM_WORLD, &status);

			printf("\n\nValor incrementado : %d \n\n", m);


    }else {/*escravo*/

            int a, b;
            MPI_Recv(&a, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);

            b = a+1;

            MPI_Send(&b, 1, MPI_INT, 0, 123, MPI_COMM_WORLD);
    }


    MPI_Finalize();

    return 0;
}



    /*
    MPI_Send(
    &n,                 --> endereço de memória onde está o dado
    1,                  --> qtde de valores que serão enviados
    MPI_INT,            --> tipo de dado que será enviado
    1,                  --> número do computador que será enviado
    4,                  --> etiqueta da mensagem
    MPI_COMM_WORLD);    --> qual grupo de processos
    */