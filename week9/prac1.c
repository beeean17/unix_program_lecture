#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main() {
    time_t t;
    struct tm *today;
    

    time(&t);

    today = localtime(&t);

    printf("%d %d %d\n", today->tm_hour, today->tm_min, today->tm_sec);


}