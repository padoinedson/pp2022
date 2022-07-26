
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pid, x;
	x = 0;

	pid = fork();   //duplica o processo

	if (pid == 0) 
		printf("\nPID - identificador do processo - filho : %d\n\n", getpid() ) ;
	else 
		printf("\nPID - identificador do processo - pai : %d\n\n", getpid() ) ;
	

	sleep(2);

	printf("\nDigite um numero: \n") ;

	scanf("%d", &x);	

	printf("\nNumero digitado: %d\n\n", x ) ;

}

