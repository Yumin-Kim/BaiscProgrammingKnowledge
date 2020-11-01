#include <stdio.h>
#include <pthread.h>

void *threadRoutine(void *argumentPointer)
{
	pthread_t id = pthread_self();
	printf("Thread ID :: %lu\n",id);
	return NULL;
}

int main()
{
	pthread_t threadID;
	printf("Create Thread! \n");

	pthread_create(&threadID , NULL ,threadRoutine , NULL);

	printf("Main Thread is now waiting for Child Thread \n");
	pthread_join(threadID,NULL);
	printf("Main Thread finish waiting Child Thread \n");
	return 0;
}
