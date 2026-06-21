# [SIGALARM]

## FLOW

struct tm given_time;

- [x] validation wheather 3 arg or 2 arg

- [x] get current time in seconds format using time() sys call 
       time_t current_time_in_seconds = time(NULL);

- [ ] convert string given time into formatted time 
        strptime(argv[1],"%D",&given_time);
                date,month/date/year format
        strptime(argv[2],"%T",&given_time);
        %T => min:sec:hr 

- [ ] convert this structure using mktime which formats to seconds
        int given_time_in_seconds = mktime(&given_time);


- [ ] call pause {waits for atleast one signal occurs}


```c

while(1) {
    alarm_occurs function  which asks 1.snooze 2.stop

    if ( snooze ) {

        read the new time 
        alarm(new time);

    } else {


    }
}

```

## [MAIN]
**Description:** [main logic]
**Notes:**
-

two options : OFF , SNOOZE
user passes date and time 
validate -> time shoud be above current time 
date is optional
eg : ./a.out 6/1/26 11:59:00
if date is not passes use current date 
were using signal here

epoc time starts from  => 1970-01-01 00:00:00

time returns in second of time_t 
-> declare an variable and store it
-> here we have to convert seconds thats the reason local time function is used 

use local time when only one parameter is there


```c
// structer is already predefined 
// 
struct tm* localtime(const time_t *  timep);

// year whatever year value from struct add with 126

```

given arguments are string for that use


```c
char* strptime(character_array(time and date),what format we want[const char*],struct tm* restrict tm);
// restrict tm is given time whic is converted and stored to first parameter 


```
mktime to convert structre to time


```c
time_t mktime(struct tm* tm);

```




**Notes:**
-

inside alarm system call were giving ( input time - current time ) 

-

## [Signal handler]

```c

// an global variable


void signal_handler() {

    

}


```




## [alarm occurs]
**Description:** [ called inside signal handler]

**Notes:**
- 

we have to check if signal flag is set or not if set then only use alarm occurs function

-


```c

if ( arg == 3 || arg == 2 ) {




}

```
