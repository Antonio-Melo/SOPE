#include <stdio.h>


#define BUF_LENGTH 512


int main(int argc,char *argv[]){
 int nr,nw;
 FILE *src, *dst;
 char buf [BUF_LENGTH];

 if(argc != 3){
    printf("Usage: %s <source> <destination>\n",argv[0]);
    return 1;
 }

 src = fopen(argv[1],"r");
 if(src == NULL){
    printf("File %s does not exist\n",argv[1]);
    return 2;		
 }

 dst = fopen(argv[2],"w");
 if(dst == NULL){
    printf("File %s does not exist\n",argv[2]);
    return 3;
 }
 
 while((nr =fread(buf,sizeof(char),BUF_LENGTH,src)) !=BUF_LENGTH){
     if((nw = fwrite(buf,sizeof(char),nr,dst)) <= 0 || nw != nr){
        perror(argv[2]);
        fclose(src);
        fclose(dst);
        return 4;   
     }
     
 }
    fclose(src);
    fclose(dst);
    return 0;

}
