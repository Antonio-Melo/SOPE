#include <stdio.h>
#include <stdlib.h>

int main(void){
	char *env;
	
	//Not working
	env = getenv("BASH_VERSION");
	printf("BASH_VERSION: %s \n",env);
	//Not working
	env = getenv("HOSTNAME");
	printf("HOSTNAME: %s \n",env);
	//Not working
	env = getenv("CDPATH");
	printf("CDPATH: %s \n",env);
	//Not working
	env = getenv("HISTFILE");
	printf("HISTFILE: %s \n",env);
	//Not working
	env = getenv("HISTSIZE");
	printf("HISTSIZE: %s \n",env);

	env = getenv("HOME");
	printf("HOME: %s \n",env);
	//Not working
	env = getenv("IFS");
	printf("IFS: %s \n",env);

	env = getenv("LANG");
	printf("LANG: %s \n",env);

	env = getenv("PATH");
	printf("PATH: %s \n",env);
	
	env = getenv("PS1");
	printf("PS1: %s \n",env);

	env = getenv("TMOUT");
	printf("TMOUT: %s \n",env);

	env = getenv("TERM");
	printf("TERM: %s \n",env);

	env = getenv("SHELL");
	printf("SHELL: %s \n",env);

	env = getenv("DISPLAY");
	printf("DISPLAY: %s \n",env);

	env = getenv("USER");
	printf("USER: %s \n",env);
	return 0;
}

