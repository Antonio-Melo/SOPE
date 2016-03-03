// PROGRAMA p6a.c
#include <stdio.h>
#include <string.h>
#include <errno.h>
#define BUF_LENGTH 256

int main(void)
{
 FILE *src, *dst;
 char buf[BUF_LENGTH];

 char  infile[30];
 char  outfile[30];
 scanf("%s",&infile);
 scanf("%s",&outfile);


 if ( ( src = fopen( infile, "r" ) ) == NULL )
 {
 perror("Error: ");
 //printf("Error: %s\n",sterror(errno));
 //printf("error: %d \n",errno); 
 exit(1);
 }
 if ( ( dst = fopen( outfile, "w" ) ) == NULL )
 {
 exit(2);
 } 

 while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
 {
 fputs( buf, dst );
 }
 fclose( src );
 fclose( dst );
 exit(0); // zero é geralmente indicativo de "sucesso"
}
