#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now;
    struct tm *tm_info;

    time(&now);                 // same as time(NULL)
    tm_info = localtime(&now);  // convert to local time

    printf("Year  : %d\n", tm_info->tm_year + 1900);
    printf("Month : %d\n", tm_info->tm_mon + 1);
    printf("Day   : %d\n", tm_info->tm_mday);
    printf("Hour  : %d\n", tm_info->tm_hour);
    printf("Min   : %d\n", tm_info->tm_min);
    printf("Sec   : %d\n", tm_info->tm_sec);

    return 0;
}

