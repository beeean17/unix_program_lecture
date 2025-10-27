#include<stdio.h>
#include<stdlib.h>

main() {
    printf("Home directory is %s\n", getenv("HOME"));
    putenv("HOME=/ ");
    printf("New home directory is %s\n", getenv("HOME"));
    printf("PATH is %s\n", getenv("PATH"));
    printf("USER is %s\n", getenv("USER"));
    printf("MANPATH is %s\n", getenv("MAIL"));
}