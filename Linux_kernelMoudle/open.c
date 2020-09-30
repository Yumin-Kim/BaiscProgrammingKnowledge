#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fdin , fdout;
	ssize_t nread;
	char buffer[1024] = {0};
	fdin = open("temp1.txt", O_WRONLY,0644);
	while((nread = read(fd:)))
}
