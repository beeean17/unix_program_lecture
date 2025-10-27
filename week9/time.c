#include <stdio.h>
#include <time.h>
void main(void)
{
time_t t;
char *ct, buf[80];
struct tm *lt;
time(&t);
ct=ctime(&t);
lt=localtime(&t);
strftime(buf,80,"%A:%B:%c:%p:%Z",lt);
//strftime(buf,80,"%c", lt);

printf("time\t: %ld\n",t);
printf("ctime\t: %s\n",ct);
printf("localtime\n");
printf("\tyear\t:%d\n", lt->tm_year);
printf("\tmon\t:%d\n", lt->tm_mon);
printf("\tday\t:%d\n", lt->tm_mday);
printf("\thour\t:%d\n", lt->tm_hour);
printf("\tminute\t:%d\n", lt->tm_min);
printf("\tseccond\t:%d\n", lt->tm_sec);
printf("\tweekday\t:%d\n", lt->tm_wday);
printf("\tyear day\t:%d\n", lt->tm_yday);
printf("strftime :%s\n", buf);
}