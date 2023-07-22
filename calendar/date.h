#include <stdio.h>
typedef struct date date;

struct date {
    int day;
    int month;
    int year;
};

// Each day will have a positive integer assigned to them starting on 01/01/1583
// Day 0: 01/01/1583 (value = 0)
// Day 1: 02/01/1583 (value = 1)
// and so on...
// this number means the amount of days between a date and 01/01/1583

int abs(int num) {
    if(num > 0)
        return num;
    return -num;
}

int isLeapYear(date d) {
    int year = d.year;
    // Leap Year conditions:
    // - the year must be multiple of 4;
    // - if multiple of 100, it has to be multiple of 400 as well;
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 1;
    return 0;
}

int getDaysInMonth(date d) {
    // January, March, May, July, August, October, December: 31 days
    // April, June, September, November: 30 days
    // February: 28 or 29 days
    int month = d.month;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 2)
        return 28 + isLeapYear(d);
    else return 30;
}

int getDaysInYear(date d) {
    // 365 if it isn't a leap year, 366 otherwise
    return 365 + isLeapYear(d);
}

int getDateValue(date d) {
    int i;
    int value = 0;
    // 1 - How many days there are from dd/mm/yyyy to 01/mm/yyyy:
    value += d.day-1;
    // 2 - How many days there are from 31/(mm-1)/yyyy to 01/01/yyyy:
    d.month--;
    while(d.month >= 1) {
        value += getDaysInMonth(d);
        d.month--;
    }
    // 3 - How many days there are from 31/12/(yyyy-1) to 01/01/1583:
    d.year--;
    while(d.year >= 1583) {
        value += getDaysInYear(d);
        d.year--;
    }
    return value;
}

char weekdays[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
// weekdays[0] = "Sunday"
// weekdays[1] = "Monday"
// and so on...

char* getWeekDay(date d) {
    // 01/01/1583 was on Saturday. We'll continue the sequence based of off this
    int day = d.day;
    int days_per_week = 7;
    int index = (6 + getDateValue(d)) % days_per_week;
    return weekdays[index];
}
