#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BUFFSIZE 8192
int main(void)
{
int n, fd_out, fd_in;
char buf[BUFFSIZE];
fd_in = open("input", O_RDONLY);
fd_out = open("output", O_RDWR | O_CREAT | O_TRUNC, 0644);
if (fd_in < 0) {
perror("open");
exit(1);
}
if (fd_out < 0) {
perror("open");
exit(1);
}


while ((n=read(fd_in,buf,BUFFSIZE))>0){
    printf("%d bytes read\n", n);
        if (write(fd_out,buf,n)!=n)
            printf("write error\n");
        if (n<0)
            printf("read error\n");

}

exit(0);
}