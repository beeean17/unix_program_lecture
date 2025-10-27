#include<stdio.h>
//#include<time.h>
#include<sys/time.h>

int main() {
    int i, j = 1;
    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    for(i = 0; i < 10000000000; i++) j++;
    gettimeofday(&end, NULL);

    printf("%d sec \n", end.tv_sec-start.tv_sec);
    printf("%d usec \n", end.tv_usec - start.tv_usec);
}