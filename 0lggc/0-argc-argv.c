

//exemplo de como passar argumentos na linha de comando
//para executar digite ./a.out 3 

#include <stdio.h>


int main(int argc,char *argv[])
{

	int i;

	printf("\nargc: %d\n", argc);

	for (i=0; i< argc; i++)
    		printf("\nargv[%d] : %s", i, argv[i]);

    	printf("\n\n");
	
	return 0;
}




