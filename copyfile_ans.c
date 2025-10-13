#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFSIZE 8192

int main(int argc, char *argv[])
{
    int n;
    int fd1, fd2;
    char buf[BUFFSIZE];

    fd1 = open(argv[1],O_RDWR);
    fd2 = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
    while ((n=read(fd1,buf,BUFFSIZE))>0)
        if(write(fd2,buf,n)!=n)
            printf("write error\n");
    if(n<0)
        printf("read error\n");
    exit(0);


}