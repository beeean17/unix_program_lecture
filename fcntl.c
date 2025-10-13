#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int fd, accmode, val;

    fd = open(argv[1], O_RDONLY);
    if((val = fcntl(fd, F_GETFL, 0))<0){
        printf("fcntl error\n");
    }

    accmode = val & O_ACCMODE;
    if(accmode == O_RDONLY){
        printf("read only\n");
    }
    
    else if (accmode == O_WRONLY){
        printf("write only\n");
    }
    
    else if (accmode == O_RDWR){
        printf("read write\n");
    }
    else printf("unknown access mode\n");
}