 
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;
 
 int main(int argc, char *argv[])
{

    char cmd [50];
    char name[] = "-l";

	sprintf(cmd, "ls %s", name);
	system(cmd);

	return 0;
}






