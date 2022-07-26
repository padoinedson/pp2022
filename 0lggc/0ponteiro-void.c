#include <stdio.h>

int main()
{

	int   	i;
	void 	*pv;

	pv = (void *)&i;

	printf("\n & variavel i -  %p", &i);
	printf("\n & variavel pv-  %p", &pv);
	printf("\n conteudo pv  -  %p\n\n", pv);
	
}
