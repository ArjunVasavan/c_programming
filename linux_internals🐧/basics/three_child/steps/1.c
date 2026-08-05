#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    

    pid_t first_child = fork();

    if ( first_child == 0 ) {
        printf("First child is Created\n");
    } else {

        pid_t second_child = fork();

        if ( second_child == 0 ) {
            printf("Second child is Created\n");
        } else {
        
            pid_t third_child = fork();

            if ( third_child == 0 ) {
                printf("third_child is Created\n");

            } else {
            
                return 0;
            }
        }

    }

}
