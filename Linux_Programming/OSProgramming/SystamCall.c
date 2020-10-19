#include <stdio.h>
#include <unistd.h>
int g_value = 0;
int main ()
{
	int l_value = 0; 
	fork();
	printf("fork1\n");
	fork();
	printf("fork2\n");
	fork();
	printf("fork3\n");
}

