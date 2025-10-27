#include<stdio.h>
#include<stdlib.h>
extern etext, edata, end;

char a = 'a';
int b = 1;
int e; int f;
int func(int arg) {
    int f = 10;
    printf("addr of arg : %p:%d\n", &arg, arg);
    printf("addr of f : %p :%d\n", &f, f);
}

main() {
    static int c = 10;
    static int d;

    int *dynamic;
        printf("end of text %p\n", &etext);
        printf("addr of a : %p :%c\n", &a, a);
        printf("addr of a : %p :%d\n", &b, b);
        printf("addr of a : %p :%d\n", &c, c);
        printf("end of initialized data %p\n", &edata);
        printf("addr of a : %p :%d\n", &d, d);
        printf("addr of a : %p :%d\n", &e, e);
        printf("addr of a : %p :%d\n", &f, f);
        printf("end of uninitialized data %p\n", &end);
        func(5);
        dynamic = (int *)malloc(8);
        *dynamic = 100;
        printf("addr of dynamic : %p :%d\n", dynamic, *dynamic);
}