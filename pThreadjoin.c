
/* Spawning POSIX pthreads to calculate sum of series and parent waiting for the termination of child thread using join for synchronized*/

#include <pthread.h>
#include <stdio.h>

int sum;
void (*runner)(void *param);

int main(int argc,char *argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	if(argc!=2){
		fprintf(stderr,"Usage: a.out <integer value\n");
		return -1;
	}
	if(atoi(argv[1])<0){
		fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
		return -1;
	}
	//initialize default attributes
	pthread_attr_init(&attr);
	//create pthread
	pthread_create(&tid,&attr,runner,argv[1]);
	//wait for the thread to exit
	pthread_join(tid,NULL);
	
	printf("Sum:%d\n",sum);
	
	return 0;
}

void (*runner)(void *param){
	int i,upper=atoi((char *)param);
	sum=0;
	
	for(i=1;i<=upper;i++)
	sum+=i;
	
	pthread_exit(0);
	
}

/*For n number of threads to wait for

pthread_t workers[NUM_THREADS];

for(int i=0;i<NUM_THREADS;i++)
	pthread_join(workers[i],NULL);

*/



