#include <stdio.h>
#include <time.h>
int main(int argc, char** argv) {
    
    time_t time_var;

    time(&time_var);

    struct tm* time_ptr;

    time_ptr = localtime(&time_var);

    int second = time_ptr->tm_sec;
    int minute = time_ptr->tm_min;
    int hour = time_ptr->tm_hour;
    int day = time_ptr->tm_mday;
    int month = time_ptr->tm_mon;
    int year = time_ptr->tm_year+1900;

    printf("Date =>");
    printf(" %d-%d-%d \n",day,month,year);
    printf("Time => ");
    printf(" %d : %d : %d \n",hour,minute,second);

}
