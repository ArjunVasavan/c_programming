#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 1024

int main(void)
{
    key_t key;
    int shmid;
    char *shmaddr;

    /* Generate unique key */
    key = ftok("shared_memory.c", 'A');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    /* Create shared memory segment */
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    /* Attach shared memory */
    shmaddr = (char *)shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    if (fork() == 0) {
        /* ---------- CHILD PROCESS ---------- */
        sleep(1);  // Wait for parent to write
        printf("Child read from shared memory: %s\n", shmaddr);
    } else {
        /* ---------- PARENT PROCESS ---------- */
        strcpy(shmaddr, "Hello from shared memory!");
        printf("Parent wrote to shared memory\n");

        sleep(2);

        /* Detach and delete shared memory */
        shmdt(shmaddr);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

