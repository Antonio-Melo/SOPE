// PROGRAMA 11.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	//system("echo $PS1");
	char* arg[] = {"export","PS1=\"minish >\"", NULL};
	execvp(arg[0],arg);
	//system("echo $PS1");
/*
	while(!stop){

	}
*/
	return 0;
}