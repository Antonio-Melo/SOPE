#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


typedef struct student{
    char name[50];
    int grade;
}STUDENT;

int main(int argc,char *argv[]){
    int dest;
    struct student students[10];
    char names[50];
    
    dest= open(argv[1],O_WRONLY |O_CREAT | O_EXCL,0600);
    if(dest == -1){
        printf("Erro\n");
        close(dest);
        return 2;
    }
    int i =0;
    
    while(fgets(names,50,stdin)!= NULL){
        strcpy(students[i].name,names);
        scanf("%d",&students[i].grade);
        i++;
    }
    
    write(dest,students,10*sizeof(students));
    close(dest);
    return 0;    
}


//f= open("persons.data",O_WRONLY | O_EXCL,0600);
//strcpy(p[0].name,"Ana");
//p[0].age = 20;
//write(f,p,10*sizeof(p));
//Calendario automatico sync google calende
