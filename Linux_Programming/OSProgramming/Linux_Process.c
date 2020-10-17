#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	//Create New Process
	pid = fork();

		printf("pid : %d\n",pid);
	if(pid < 0)
	{
		fprintf(stderr,"Fork Faild");
		return 1;
	}
	else if(pid == 0)
	{
		printf("pid : %d\n",pid);
		execlp("/bin/ls","ls",NULL);
	}
	else
	{
		printf("Parent Proces\n:");
		printf("pid : %d\n",pid);
		wait(NULL);
		printf("Child Complete\n");
	}
	return 0;
}

