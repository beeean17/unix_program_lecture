#include<stdio.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int c;
	
	if((fp = fopen(argv[1], "a"))==NULL)
//	if((fp = fopen(argv[1], "w"))==NULL)
		perror("fopen:");
	fprintf(fp, "Helloworld\n");
}
