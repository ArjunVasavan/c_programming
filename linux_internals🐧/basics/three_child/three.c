/*
--------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 09 - 12 - 2025

Description : Program to create three child from the same parent

Sample execution: 

Child 1 with pid 2020 created 
Child 2 with pid 2021 created
Child 3 with pid 2022 created 
Child 2020 is terminated with code 0 
Child 2021 is terminated with code 0 
Child 2022 is terminated with code 0

--------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

    // using single parent to create 3 child

    pid_t child_1 = fork();

    if ( child_1 > 0 ){ // parent

        pid_t child_2 = fork();

        if ( child_2 > 0 ){ // parent

            pid_t child_3 = fork();


            if ( child_3 > 0 ){ // parent

                int status;

                for ( int i = 1 ; i <= 3 ; i++ ){

                    pid_t collect = wait(&status);

                    if ( WIFEXITED(status)){

                        printf("Child %d is terminated with code %d\n",collect,WEXITSTATUS(status));

                    }

                }

            } else { // child 3
                printf("Child 3 with pid %d created\n",getpid());
                sleep(3);


            }

        } else { // child 2
            printf("Child 2 with pid %d creted\n",getpid());
            sleep(2);

        }


    } else { // child 1
        printf("Child 1 with pid %d created\n",getpid());
        sleep(1);

    }


}
