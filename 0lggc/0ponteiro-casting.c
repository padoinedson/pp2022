#include <stdio.h>

int main()
{

	int   i;
	float f;

	i = 5;
	f = 9.9876;

	i = f;
		
	printf("\n inteiro -  %d", i);
	printf("\n float   -  %f", f);

	i = (int) f;

	printf("\n inteiro com valor do float -  %d\n\n\n", i);

	
}
