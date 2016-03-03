#include <stdio.h>
#include <string.h>

int main(){

 char cmd[256];
 char * tcmd;

 char* array[10];

 fgets(cmd,sizeof(cmd),stdin);
 printf("Tokens: \n");

 tcmd = strtok(cmd," ");
 //array[0] = strdup(tcmd);
 //printf("%s",array[0]);

 int i = 0;
 while (tcmd != NULL)
  {
    //printf ("%s\n",tcmd);
    array[i] = strdup(tcmd);
    tcmd = strtok (NULL, " ");
    i++;
  }

  int x;
  for(x= 0; x < i+1;x++){
	printf("%s\n",array[x]);
  }

  return 0;

}
