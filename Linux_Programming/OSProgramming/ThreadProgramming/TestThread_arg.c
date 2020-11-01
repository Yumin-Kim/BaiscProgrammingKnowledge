#include <stdio.h>
#include <pthread.h>

void *threadRoutine(void *argumentPointer)
{
	char *argument = (char *)argumentPointer;
	printf("Print ThreadRoutine :: %s\n",argument);
	return NULL;
}

int main()
{
	pthread_t threadID;
	printf("Create Thread \n");

	char *argument = "Working Thread";

	pthread_create(&threadID , NULL , threadRoutine , (void*)argument);
	printf("Main Thread is now waiting for Child Thread\n");

	pthread_join(threadID , NULL);
	printf("main Thread finish waiting Child Thread");
	return 0;
}
