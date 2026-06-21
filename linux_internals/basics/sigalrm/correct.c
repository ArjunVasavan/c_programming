#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

int alarm_flag = 0;

void alarm_handler(int signo)
{
    alarm_flag = 1;
}

int main(int argc, char *argv[])
{
    struct tm alarm_tm = {0};
    time_t now, target;
    int delay;


    if (argc == 1) {
        printf("Error: No arguments passed\n");
        printf("Usage: %s <HH:MM> [DD/MM/YY]\n", argv[0]);
        return 1;
    }

    if (argc > 3) {
        printf("Error: Too many arguments\n");
        return 1;
    }


    if (!strptime(argv[1], "%H:%M", &alarm_tm)) {
        printf("Error: Invalid time\n");
        return 1;
    }

    now = time(NULL);
    struct tm *current = localtime(&now);

    if (argc == 3) {
        if (!strptime(argv[2], "%d/%m/%y", &alarm_tm)) {
            printf("Error: Invalid date\n");
            return 1;
        }
    } else {
        /* today’s date */
        alarm_tm.tm_mday = current->tm_mday;
        alarm_tm.tm_mon  = current->tm_mon;
        alarm_tm.tm_year = current->tm_year;
    }

    target = mktime(&alarm_tm);
    delay = difftime(target, now);

    if (delay <= 0) {
        printf("Error: Time is in the past\n");
        return 1;
    }

    printf("Alarm set for %02d:%02d\n",
           alarm_tm.tm_hour, alarm_tm.tm_min);


    signal(SIGALRM, alarm_handler);


    while (1) {
        alarm_flag = 0;
        alarm(delay);

        while (!alarm_flag)
            pause();

        printf("\nAlarm..!!\n");
        printf("1. Snooze\n2. Exit\nChoice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter snooze time (minutes): ");
            int mins;
            scanf("%d", &mins);
            delay = mins * 60;   // repeat after snooze
        } else {
            break;
        }
    }

    return 0;
}

