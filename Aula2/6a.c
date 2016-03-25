// PROGRAMA p6a.c ( referido na alínea a) )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
int main(int argc, char *argv[])
{
 DIR *dirp;
 struct dirent *direntp;
 struct stat stat_buf;
 //char *str;
 char dir[100];
 
 if (argc != 2)
 {
 fprintf( stderr, "Usage: %s dir_name\n", argv[0]);
 exit(1);
 }
 if ((dirp = opendir( argv[1])) == NULL)
 {
 perror(argv[1]);
 exit(2);
 }
 
 while ((direntp = readdir( dirp)) != NULL)
 {
    sprintf(dir,"%s/%s",argv[1],direntp->d_name); 
    int erro =stat(dir, &stat_buf);
    if(erro != 0){
        perror(dir);
    }else{
        int line =1;
        //if (S_ISREG(stat_buf.st_mode)) str = "regular";
        //else if (S_ISDIR(stat_buf.st_mode)) str = "directory";
        //else str = "other";
        //printf("%-25s - %s\n", direntp->d_name, str);
        if (S_ISREG(stat_buf.st_mode)) {
            printf("%-25s%12d%3d\n", direntp->d_name,(int)stat_buf.st_size,(int)stat_buf.st_nlink);
            if (line++ % 20 == 0) {
                printf("Press <enter> to continue");
                getchar();
            }
        } 
    
    }
 }
 closedir(dirp);
 exit(0);
 }