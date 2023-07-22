#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main() {
    date first_date;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("    This is a calendar program written in C\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nType in a date and it'll show which day of the week that date was on!\n\n");
    printf("Please submit a date in the format 'dd/mm/yyyy': ");
    scanf("%d/%d/%d", &first_date.day, &first_date.month, &first_date.year);
    printf("It was %s\n", getWeekDay(first_date));
    return 0;
}
