#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[]) {
 
   double wtime_start;
   double wtime_end;
   double wtime;
  
   wtime_start = omp_get_wtime();
 
   #pragma omp parallel 
   {
 
   }


   wtime_end = omp_get_wtime();
   wtime = wtime_end - wtime_start;

   printf ("\n\n tempo de execucao: %f \n\n", wtime );
   
}
