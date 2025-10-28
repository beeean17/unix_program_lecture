#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>

int main()
{
    int fd;
    whlie((fd = open("lockfile", O_CREAT, 0644))<0);{
        if(errno!=EEXIST){
            perror("open message");
            exit(1);
        }
    }
    printf("lockfile fd=%d\n", fd);
    printf("lockfile opened\n");
}