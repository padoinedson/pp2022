
#include <stdio.h>

void printNumber(int number)
{
  printf(" CPU - iteration= %d\n", number);
}


int main()
{
  for (int i = 0; i < 5; ++i)
  {
    printNumber(i);
  }

}



 

