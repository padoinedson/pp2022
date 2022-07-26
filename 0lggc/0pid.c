


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	int x;

	x = 0;

	printf("\nPID - identificador do processo : %d\n\n", getpid() ) ;

	printf("\nDigite um numero: ") ;

	scanf("%d", &x);	

	printf("\nNumero digitado: %d\n\n", x ) ;

}


