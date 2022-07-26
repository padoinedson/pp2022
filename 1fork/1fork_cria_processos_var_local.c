

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pid, x;
	x = 1;
	printf("\nx: %d\n\n", x ) ;



	pid = fork();   //duplica o processo


	if (pid != 0) {
		x = x + 5;
		printf("\nx no processo pai: %d\n\n", x ) ;
	}
	else {
		x = x + 10;
		printf("\nx no processo filho: %d\n\n", x ) ;
	}
	

		printf("\nx: %d\n\n", x ) ;

}

