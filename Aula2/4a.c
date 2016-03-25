#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_LENGTH 512
int main(int argc,char *argv[]){
    int fd1,nr,nw;
    unsigned char buffer [BUF_LENGTH];
    
    if (argc != 2) {
        printf("%s <destination>\n",argv[0]);
        return 1;
    }
    
    fd1 = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd1 == -1) {
        perror(argv[1]);
        close(fd1);
        return 2;
    }
    
    while((nr = read(STDIN_FILENO,buffer,BUF_LENGTH))>0){
        if((nw = write(fd1,buffer,nr)) <= 0 || nw !=nr){
            perror(argv[1]);
            close(fd1);
            return 3;
        }
    }
    close(fd1);
    return 0;
    
}

