#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BUFFSIZE 8192
int main(void)
{
int n;
char buf[BUFFSIZE];
while ((n=read(STDIN_FILENO,buf,BUFFSIZE))>0){
    printf("%d bytes read\n", n);
        if (write(STDOUT_FILENO,buf,n)!=n)
            printf("write error\n");
    if (n<0)
        printf("read error\n");

}

exit(0);
}