#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
void main() {

    pid_t pid;

    printf("Hello, my pid is %d\n", getpid());

    if ((pid = fork()) == 0) { /* child process */
        printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
    } else {    /* parent process */
        printf("parent: I created child with pid=%d\n",pid);
    }
/* Following line is executed by both parent and child */
    printf("Bye, my pid is %d\n", getpid());
    sleep(20);
}