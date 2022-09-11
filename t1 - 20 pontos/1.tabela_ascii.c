#include <stdio.h>
#include <stdlib.h>

void main() {
 
   char c;
   int  i;


   printf("\n-------------------------------------------------------------------");
   printf("\n\nUsando char\n");

   for (c = 32; c < 127; c++)
      printf("\nPos %d: char %c \t", c, c);  


   printf("\n-------------------------------------------------------------------");
   printf("\n\nUsando int\n");

   for (i = 32; i < 127; i++)
      printf("\nPos %d: char %c \t", i, i);  

   printf("\n\n"); 

}
