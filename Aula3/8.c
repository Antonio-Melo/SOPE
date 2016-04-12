// PROGRAMA p8.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[])
{
 	pid_t pid;
 	if (argc != 2) {
 		printf("usage: %s dirname\n",argv[0]);
 		exit(1);
 	}
 	pid=fork();
 	if (pid > 0)
 		printf("My child is going to execute command: ls -laR %s\"\n", argv[1]);
 	else if (pid == 0){
 		//a)
 		//execlp("ls", "ls", "-laR",(char *)NULL);
 		//b)
 		//execl("/bin/ls","/bin/ls", "-laR",(char *)NULL);
 		//c)
 		char* arg[] = {"/bin/ls","-laR",NULL};
 		//execvp(arg[0],arg);
 		//d)
 		//execv(arg[0],arg);
 		//e)
 		execve(arg[0],arg,envp);
 		printf("Command not executed !\n");
 		exit(1);
 	}
 exit(0);
} 