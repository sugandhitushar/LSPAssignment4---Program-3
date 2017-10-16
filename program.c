#include"program.h"

void *ThreadProc(void *arg)
{
	int argument = *((int *) arg);
	
	printf("Argument passed to thread: %d\n",argument);	
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret,val=10;
	
	ret = pthread_create(&thread, NULL, ThreadProc,&val);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	pthread_join(thread,NULL);
	printf("Threads terminated.\n");
	
	pthread_exit(NULL);
	return 0;
}

