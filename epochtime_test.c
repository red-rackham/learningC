#include <time.h>
#include <stdio.h>
#include <stdint.h>



long epochtime;

//    struct tm t;
//    time_t t_of_day;

void main();
void convertToEpochTime();
int e2h(void);
void e2conv();

uint16_t    year = 2018;
uint8_t    month = 10;
uint8_t     day = 11;
uint8_t     hour = 22;
uint8_t     minute = 21;
uint8_t     second = 20;

void main() {

    e2conv();

    printf("Epoch Time = %li\n", (long) epochtime);

/*
    struct tm t;
    time_t t_of_day;

    convertToEpochTime();
    printf("Epoch Time = %li\n", (long) epochtime);
    printf("%ld\n", (long) t_of_day);

    e2h();
 



    t.tm_year = 2018-1900;
    t.tm_mon = 10;           // Month, 0 - jan
    t.tm_mday = 11;          // Day of the month
    t.tm_hour = 22;
    t.tm_min = 21;
    t.tm_sec = 20;
    t.tm_isdst = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
    t_of_day = mktime(&t);

    printf("seconds since the Epoch: %ld\n", (long) t_of_day);
    */
}

void e2conv(){
    struct tm t;
    time_t t_of_day;

    t.tm_year = year-1900;
    t.tm_mon = month;           // Month, 0 - jan
    t.tm_mday = day;          // Day of the month
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = second;
    t.tm_isdst = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
    t_of_day = mktime(&t);

    printf("seconds since the Epoch: %ld\n", (long) t_of_day);

    epochtime = t_of_day;



}


int e2h()
{
//    time_t     now;
    struct tm  ts;
    char       buf[80];

    // Get current time
//    time(&now);

    // Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
    ts = *localtime(&epochtime);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
    printf("%s\n", buf);
    return 0;
}

void convertToEpochTime(){


   struct tm t2;
   time_t t_of_day;

    t2.tm_year = year;
    t2.tm_mon = month;
    t2.tm_mday = day;
    t2.tm_hour = hour;
    t2.tm_min = minute;
    t2.tm_sec = second;
    t2.tm_isdst = 0;        // Daylight Saving Time on
    t_of_day = mktime(&t2);

    epochtime = t_of_day;
}
