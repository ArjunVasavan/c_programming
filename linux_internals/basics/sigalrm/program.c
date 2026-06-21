#define _XOPEN_SOURCE  
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

// NOTE: argv[1] => Time , argv[2] => date

void validate_argc( int argc ) {

    if (  argc <= 1 ) {
        fprintf(stderr,"Error: No arguments passed\nUsage: ./alarm  [dd/mm/yy]\n");
        exit(1);
    } else if ( argc > 3 ) {
        fprintf(stderr,"Usage: ./alarm  [dd/mm/yy]\n");
        exit(1);
    } 
}

int alarm_flag = 0;

void alarm_handler( int signum ) {

    if ( signum == SIGALRM ) {
        alarm_flag = 1;
    }

}

int main(int argc, char** argv) {

    struct tm user_input;

    validate_argc(argc);

    time_t current_time_sec = time(NULL);

    if ( strptime(argv[1],"%T",&user_input) == 0  ) {
        fprintf(stderr,"[ERROR]: %s \n",argv[1]);
        exit(1);
    }

    struct tm *local_time = localtime(&current_time_sec);

    if ( argc == 3 ) {

        if ( strptime(argv[1],"%T",local_time) == NULL ) {
            fprintf(stderr,"[ERROR]: %s \n",argv[1]);
            exit(1);
        }

        user_input.tm_mday = local_time->tm_mday;
        user_input.tm_mon = local_time->tm_mon;
        user_input.tm_wday = local_time->tm_wday;
        user_input.tm_yday = local_time->tm_yday;
        user_input.tm_year = local_time->tm_year;

    }
    
    time_t user_input_sec  = mktime(&user_input);

    time_t delay = difftime(user_input_sec,current_time_sec);

    if ( delay <= 0 ) {
        fprintf(stderr,"Error: Invalid time\n");
        exit(1);
    }

    signal(SIGALRM,alarm_handler);

    while( true ) {

        alarm(delay);

        pause();

        if ( alarm_flag == 1 ) {

            printf("Wakeup...Alarm...!!\n\n1. Snooze\t\t2. Exit\n");

            char choice;

            scanf("%hhd",&choice);

            switch (choice) {
            
                case 1 : {


                    break;
                }

                case 2 : {

                    exit(0);
                    break;
                }

            }
        }

    }
}

