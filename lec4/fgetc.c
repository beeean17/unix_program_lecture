#include<stdio.h>
#include<errno.h>

int main(int argc, char *argv[]){
    FILE *fp;
    int c;

    if((fp = fopen(argv[1], "r"))==NULL)
        perror("fopen:");
    //fprintf(fp, "helloworld\n");

    c = fgetc(fp);
    while (c != EOF){
        putchar(c);
        c = fgetc(fp);
    }

}
