#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
int main(void)
{
int fd;
fd = creat("dup_result", 0644);
dup2(fd, STDOUT_FILENO);
//close(fd);
printf("hello world\n");
//fflush(stdout);
write(fd,"fd write\n",10);
return 0;
}
