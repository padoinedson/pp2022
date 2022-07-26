

#include <stdio.h>

int main()
{
	char c;
	unsigned u;
	short s;
	unsigned short us;
    int i;
	float f;
	long l;
	double d;
	
	printf("\n tam char    -  %ld", sizeof(c));

	printf("\n tam unsigned-  %ld", sizeof(u));

	printf("\n tam short   -  %ld", sizeof(s));

	printf("\n tam un short-  %ld", sizeof(us));
	
	printf("\n tam inteiro -  %ld", sizeof(i));
	
	printf("\n tam float   -  %ld", sizeof(f));

	printf("\n tam long    -  %ld", sizeof(l));

	printf("\n tam double  -  %ld", sizeof(d));
	



	struct {
		int a;
		double c;
	} w;


	union {
		int aa;
		double cc;
	} k;

	printf("\n\n tam struct  -  %ld", sizeof(w));

	printf("\n tam union   -  %ld", sizeof(k));

	printf("\n tam union aa -  %ld", sizeof(k.aa));

	printf("\n tam union cc -  %ld", sizeof(k.cc));

	printf("\n\n ");

}



/*
signed char: -127 to 127 (note, not -128 to 127; this accommodates 1's-complement platforms)
unsigned char: 0 to 255
"plain" char: -127 to 127 or 0 to 255 (depends on default char signedness)
signed short: -32767 to 32767
unsigned short: 0 to 65535
signed int: -32767 to 32767
unsigned int: 0 to 65535
signed long: -2147483647 to 2147483647
unsigned long: 0 to 4294967295
signed long long: -9223372036854775807 to 9223372036854775807
unsigned long long: 0 to 18446744073709551615
*/
