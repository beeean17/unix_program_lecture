#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include<stdlib.h>
#include <unistd.h>
int main() {
    pid_t pid;
    int status;
    if ((pid = fork()) == 0) { /* child */
    printf("I am a child with pid = %d\n", getpid());
    sleep(60);
    printf("child terminates\n");
    exit(0);
    }
    else {
        /* parent */
        while (1) {
        waitpid(pid, &status, WUNTRACED);
        if (WIFSTOPPED(status)) {
            printf("child stopped, signal(%d)\n", WSTOPSIG(status));
            continue;
        }
        else if (WIFEXITED(status))
            printf("normal termination with status(%d)\n", WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            printf("abnormal termination, signal(%d)\n", WTERMSIG(status));
        exit(0);
    }
}
}