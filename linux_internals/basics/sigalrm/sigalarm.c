
#define _XOPEN_SOURCE 700 // for strptime();
#include <time.h>  // for strptime();
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>

int signal_flag = 0;

void signal_handler(int signo) {

    if ( signo == SIGALRM) {
        signal_flag = 1;
    }

}


int main(int argc, char **argv) // argv[1] => time argv[2] => date
{
    struct tm given_time_and_date = {0};

    struct tm* current_time_and_date;

    if (argc != 2 && argc != 3) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    time_t current_time_in_seconds = time(NULL);

    strptime(argv[1], "%T", &given_time_and_date);
    strptime(argv[2],"%D",&given_time_and_date);
    time_t given_time_and_date_in_SECONDS = mktime(&given_time_and_date);

    int delay = difftime(given_time_and_date_in_SECONDS,current_time_in_seconds);

    if ( delay <= 0 ) {
        // TODO: print  time is in past error

    }

    signal(SIGALRM,signal_handler);

    while (1) {

        signal_flag = 0 ;

        alarm(delay);

        while ( signal_flag != 1 ) {
            pause();
        }

        printf("Alarm Called\n");

        printf("Do you want to snooze : y/n ? ");
        char choice;
        scanf(" %c",&choice);

        if ( choice == 'y' ) {

            printf("Enter snooze time : ");
            int snooze_time;
            scanf("%d",&snooze_time);

            delay = snooze_time;

        } else {

            exit(0);
        }


    }


    return 0;
}

