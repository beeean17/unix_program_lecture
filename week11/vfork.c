#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int glob = 6;
char buf[] = "a write to stdout\n";
int main(void) {
    int var;
    pid_t pid;
    var = 88;

//    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) !=sizeof(buf)-1) {
//        perror("write error");
//        exit(1);
//    }
    printf("before vfork\n");
     /* we don't flush stdout */
    if ( (pid = fork()) < 0) {
        perror("vfork error");
//        exit(1);
    }
    else if (pid == 0) {    
        glob++;         //modify parent's variable
        var++;
        _exit(0);       //child termination
    }
    else sleep(2);
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    exit(0);
}
