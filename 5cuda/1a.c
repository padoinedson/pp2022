#include <stdlib.h>
#include <stdio.h>

void CPUFunction()
{
  printf("CPU - rodando ...U.\n");
}

void GPUFunction()
{
  printf("GPU - rodando ....\n");
}

int main()
{
  CPUFunction();

  GPUFunction();
}


