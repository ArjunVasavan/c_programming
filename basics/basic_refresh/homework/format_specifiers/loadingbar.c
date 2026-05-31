#include <stdio.h>
#include <unistd.h>
int main() {
    int i, j;
    for (i = 0; i <= 100; i++) {
        printf("\rLoading: [");
        for (int k = 0; k < i; k++) printf("#");
        for (int k = i; k < 100; k++) printf(" ");
        printf("] %d%%", i);
        fflush(stdout);
        usleep(20500);
    }
    usleep(10050);
    printf("\n \t \t \t \t \t  \t  Completed Successfully!\n");
}


