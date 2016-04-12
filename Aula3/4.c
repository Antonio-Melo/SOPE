#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
	pid_t pid;
	char str[10];

	pid=fork();

	if(pid == -1){
		perror("fork");
		return -1;
	}

	if(pid == 0){//filho
		sprintf(str,"Hello");
		write(STDOUT_FILENO,str,strlen(str));
		return 0;
	}else{//pai
		sprintf(str,"world\n");
		write(STDOUT_FILENO,str,strlen(str));
		return 0;
	}

	return 0;
}