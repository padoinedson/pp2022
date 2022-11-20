

//mpirun -np 3 --host Aspire,Aspire,Aspire ex4

//criar um arquivo com nome my-hosts e colocar Aspire Aspire Aspire (um em cada linha)
//mpirun -np 3 --hostfile my-hosts ex4


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

int main(int argc,char *argv[])
{
    MPI_Status status;
    int  myid, numprocs;


    MPI_Init(&argc,&argv);

    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	#ifdef DEBUG
	printf("\nNumero total de processos: %d", numprocs);
	#endif

    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	#ifdef DEBUG
	printf("\nMeu id: %d", myid);
	#endif




/////////////////////////////////////*mestre*/////////////////////////////////////
    if (myid == 0) 
    {


        int n, m, valor1, valor2;

        printf("\nDigite m:");
        scanf("%d",&m);

        printf("\nDigite n:");
        scanf("%d",&n);



//envia para nodo 1
        MPI_Send(&m, 1, MPI_INT, 1, 4, MPI_COMM_WORLD);
        MPI_Send(&n, 1, MPI_INT, 1, 4, MPI_COMM_WORLD);


//envia para nodo 2
        MPI_Send(&m, 1, MPI_INT, 2, 4, MPI_COMM_WORLD);
        MPI_Send(&n, 1, MPI_INT, 2, 4, MPI_COMM_WORLD);


//recebe do nodo 1
        MPI_Recv(&valor1, 1, MPI_INT, 1, 4, MPI_COMM_WORLD, &status);

        printf("\n\nSoma = %d \n\n", valor1);


//recebe do nodo 2
        MPI_Recv(&valor2, 1, MPI_INT, 2, 4, MPI_COMM_WORLD, &status);

        printf("\nMultiplicação = %d \n\n", valor2);




    } 


/////////////////////////////////////*escravo 1 */////////////////////////////////////
    if (myid == 1) /*slave*/
    {

            int a, b, s1;
            MPI_Recv(&a, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
            MPI_Recv(&b, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);

            s1 = a + b;

            MPI_Send(&s1, 1, MPI_INT, 0, 4, MPI_COMM_WORLD);
    }




/////////////////////////////////////*escravo 2 */////////////////////////////////////

    if (myid == 2) /*slave*/
    {

            int x, y, s2;
            MPI_Recv(&x, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
            MPI_Recv(&y, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);

            s2 = x * y;

            MPI_Send(&s2, 1, MPI_INT, 0, 4, MPI_COMM_WORLD);
    }


    MPI_Finalize();

    return 0;
}




