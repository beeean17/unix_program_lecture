#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<unistd.h>

int main() {
    struct rlimit rlim;

    getrlimit(RLIMIT_FSIZE, &rlim);
    printf("soft :%lu, hard %lu \n", rlim.rlim_cur, rlim.rlim_max);
    getrlimit(RLIMIT_NOFILE, &rlim);
    printf("soft :%lu, hard %lu \n", rlim.rlim_cur, rlim.rlim_max);
    getrlimit(RLIMIT_CPU, &rlim);
    printf("soft :%lu, hard %lu \n", rlim.rlim_cur, rlim.rlim_max);
    getrlimit(RLIMIT_DATA, &rlim);
    printf("soft :%lu, hard %lu \n", rlim.rlim_cur, rlim.rlim_max);
    getrlimit(RLIMIT_NPROC, &rlim);
    printf("soft :%lu, hard %lu \n", rlim.rlim_cur, rlim.rlim_max);
}