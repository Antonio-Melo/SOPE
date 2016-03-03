#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	srand(time(NULL));
	int n1,n2,i;
	int x;
	i =0;
	scanf("%d",&n1);
	scanf("%d",&n2);
	clock_t tStart = clock();
	do{
		x = rand() % n2 + n1;	
		printf("%d - %d \n",i,x);
		i++;	
	}while(x != n2);

	printf("Real time: %.20fs\n",(double)(clock()-tStart)/CLOCKS_PER_SEC);
	printf("Clock time: %f\n", (double)(clock()-tStart);

	return 0;	

}
