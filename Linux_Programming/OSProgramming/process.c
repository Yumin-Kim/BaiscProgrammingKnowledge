#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main(){
	pid_t pid;
	printf("Start Process\n");
	pid = fork();
	/*
	printf("Start Process fork()1\n");
	fork();
//	printf("Start Process fork()2\n");
	fork();

	printf("Start Process fork()3 \n");
	*/
	
	
	printf("Fork() Systam Call \n");
	printf("pid = %d \n",pid);
	if(pid == 0){
		printf("Child Process >> pid %d \n ",pid);
		value += 15;
		printf("Child Process >> value %d \n ",value);
		return 0;
	}
	else if(pid > 0){
		printf("kill Parent Process \n");
		wait(NULL);
		printf("Value = %d\n",value);
		return 0;
	}
	
}

