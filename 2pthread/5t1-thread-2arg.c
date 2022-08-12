
//como passar mais de um argumento para a threads


#include <stdio.h>
#include <pthread.h>


typedef struct {
   int i1, 
	   i2;
}var_struct;


void *funcaot(void *arg);


int main(int argc, char *argv[])
{

    pthread_t t1;


	var_struct args;
    var_struct args2;

 	args.i1 = 10;
    args.i2 = 20;

    args2.i1 = 10;
    args2.i2 = 20;

    var_struct objetos[2];
    objetos[0] = args;
    objetos[1] = args2;

	pthread_create(&t1, NULL, funcaot, (void *)&(args));  

	pthread_join(t1, NULL);

	pthread_exit(NULL);
}


void * funcaot(void *arg)
{	
        int a,b;  

		var_struct *pont;

		pont = arg;

        a = pont->i1;
        b = pont->i2;

        printf("\ni1 = %d  \ni2 = %d \n",a, b);


//ou assim

	var_struct argument = *((var_struct*)arg);
 
        a = argument.i1;
        b = argument.i2;

        printf("\ni1 = %d  \ni2 = %d \n",a, b);

		return(NULL);
}



