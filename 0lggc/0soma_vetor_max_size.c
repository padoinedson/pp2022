#include <stdio.h>
#define MAX 512*1024*1024 - 250 
int big[MAX] ;
int main ( ) {
	

	unsigned long x=0, i = MAX;
//	printf( "Tamanho i %ld\n", MAX );
	printf( "Tamanho i %d\n", MAX );

//	for (i=0; i < MAX; i++) 
//			x++;
	
//	printf( "Tamanho x %ld\n", x );
	
		
    printf( "Tamanho MAX %d\n", MAX );
    printf( "Tamanho alocado %lu\n", (unsigned long)sizeof big );
    return 0;
}

