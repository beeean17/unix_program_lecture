#include <stdio.h>
#include <stdarg.h>

int sum(int val, ...)
{
    va_list arglist;
    int arg, total;

    va_start(arglist, val);
    total = val;
    while ((arg = va_arg(arglist, int)) != 0)
        total += arg;
    va_end(arglist);
    return (total);
}

main()
{
printf("Total sum: %d\n", sum(1,2,3,4,5,0));
printf("Total sum: %d\n", sum(1,2,0));
printf("Total sum: %d\n", sum(1,2,5,0));
printf("Total Sum test: %d\n", sum(1,2,3,4,5));
//printf("Total Sum test2: %d\n", sum(1,2,3,0));
}