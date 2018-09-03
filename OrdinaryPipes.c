#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void){
	char write_mesg[BUFFER_SIZE]="Greetings";
	char read_mesg[BUFFER_SIZE];
	
	int fd[2];
	pid_t pid;
	
	if(pipe(fd)==-1){
		fprintf(stderr,"pipe failed");
		return 1;
	}
	pid=fork();
	
	if(pid<0){
		fprintf(stderr,"Fork failed");
		return 1;
	}
	
	if(pid>0){//Parent
		close(fd[READ_END]);
		write(fd[WRITE_END],write_mesg, strlen(write_mesg)+1);
		close(fd[WRITE_END]);
	}
	else{//Child
		close([fd[WRITE_END]);
		read(fd[READ_END],read_mesg,BUFFER_SIZE);
		close(fd[READ_END]);
	}
	
	return 0;
}
