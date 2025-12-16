#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
// shm2.c
#define KEY 0x101010
#define SIZE 1024
main()
{
    int shmid;
    void *shmaddr;
    if((shmid=shmget(KEY, SIZE, IPC_CREAT|0666)) == -1) {
        perror("shmid failed");
        exit(1);
    }
    if((shmaddr=shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }
    printf("%d\n", shmid);
    printf("data read from shared memory : %s\n", (char*)shmaddr);
    strcpy((char *)shmaddr, "I'm shm2.c");
    sleep(5);
    if(shmdt(shmaddr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    if(shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl failed");
        exit(1);
    }
}