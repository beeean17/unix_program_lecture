#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include<stdlib.h>
#define LOCKFILE "lockfile"
#define DELAY 10000000
void delay(void)
{
int i;
for (i = 0; i < DELAY; i++);
}

int main(void)
{ int fd, i;
while ((fd = open(LOCKFILE, O_WRONLY | O_CREAT |
O_EXCL, 0644)) < 0) {
if (errno != EEXIST) {
perror("open");
exit(1);
}
}
for (i = 'a'; i <= 'z'; i++) {
putchar(i);
fflush(stdout);
delay();
}
close(fd);
unlink(LOCKFILE);
return 0;
}