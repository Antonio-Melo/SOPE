#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
	pid_t pid;
	char str[10];
	//int status;

	pid=fork();

	if(pid == -1){
		perror("fork");
		return -1;
	}

	if(pid == 0){//filho
		pid = fork();
		if(pid == 0){//neto
			sprintf(str,"friends!");
			write(STDOUT_FILENO,str,strlen(str));
			return 0;
		}else{
			sprintf(str,"my ");
			write(STDOUT_FILENO,str,strlen(str));
			wait();
			return 0;
		}
	}else{//pai
		sprintf(str,"Hello ");
		write(STDOUT_FILENO,str,strlen(str));
		//waitpid(-1, &status, 0);
		wait();
		return 0;
	}




	return 0;
}