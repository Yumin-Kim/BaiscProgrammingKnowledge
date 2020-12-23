#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *t_function(void *data)
{
	int num = *((int *)data);
	printf("num %d \n",num);
	sleep(1);
	num *= num;
	printf("Called Thread Function\n");
	return (void *)(num);
}
int main()
{
	pthread_t pthread;
	int thread_id , result , a = 200;

	thread_id = pthread_create(&pthread , NULL , t_function , (void *)&a);
	if(thread_id)
	{
		perror("thread create Error");
		exit(0);
	}
	pthread_join(pthread,(void *)&result);
	printf("Thread Join : %d\n",result);
	printf("Called Main()\n");
	return 0;
}
