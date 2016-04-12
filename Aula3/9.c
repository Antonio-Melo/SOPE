#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
 int pid;
 int status;
 pid=fork();
 if (pid > 0) {
 	//waitpid(-1,&status,0);
 	wait(&status);
 	printf("I'm the parent (PID=%d)\n\n",getpid());
 	printf("My son exited with EXIT CODE = %d\n",WEXITSTATUS(status));}
 else {
	printf("I'm the son (PID=%d)\n\n",getpid());
 	execlp("ls","ls","-laR",NULL); //try with execl()
 	printf(".... \n"); //which message makes sense, here ?
 }
 printf ("PID=%d exiting ...\n",getpid());
 return 0;
} 