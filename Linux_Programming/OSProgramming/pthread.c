#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void *runner(void *param);

int main()
{
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1])
}

