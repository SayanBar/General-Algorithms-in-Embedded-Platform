
/* Consumer process illustrating POSIX shared-memory API*/

#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main(){
	const int SIZE=4096;//Size of shared memory object
	const char *NAME="os";//Name of shared memory
	
	int shm_fd;//Shared memory file descriptor
	void *ptr;//Pointer to shared memory
	
	shm_fd=shm_open(NAME,0_RDONLY,0666);
	
	ptr=mmap(0,SIZE,PROT_WRITE, MAP_SHARED, shm_fd,0);
	
	printf("%s",(char *)ptr);
	
	shm_unlink(NAME);
	
	return 0;
	
}
