
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	int i;
	i = 5;

	printf("\n & memoria da variavel i -  %p", &i);
	printf("\n conteudo i   -  %d\n", i);



	int	*pi;
	pi = &i;

	printf("\n & memoria da variavel pi-  %p", &pi);
	printf("\n conteudo pi  -  %p\n", pi);
	

	*pi = 10;
	printf("\n conteudo i   -  %d", i);
	printf("\n conteudo *pi   -  %d\n\n", *pi);

}








