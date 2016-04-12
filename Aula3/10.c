// PROGRAMA 10.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
 	pid_t pid;
 	pid=fork();
 	if (pid > 0)
 		printf("My child is going to execute command: ls -laR %s\"\n", argv[1]);
 	else if (pid == 0){
 		if (argc == 3) {
 			char * str[80];
 			strcpy(str,"ls -laR > ");
 			strcat(str,argv[2]);
 			system(str);
 		}else{
 		system("ls -laR  > test.txt");
 		}
 		exit(1);
 	}
 exit(0);
} 