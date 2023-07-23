#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main() {
    date first_date;
    date second_date;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("    This is a calendar program written in C\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nType in 2 dates and it'll show how many days there are between them!\n\n");
    printf("Please submit a date in the format 'dd/mm/yyyy': ");
    scanf("%d/%d/%d", &first_date.day, &first_date.month, &first_date.year);
    printf("Now submit another date in the format 'dd/mm/yyyy': ");
    scanf("%d/%d/%d", &second_date.day, &second_date.month, &second_date.year);
    printf("\nThere are %d day(s) between %02d/%02d/%d and %02d/%02d/%d\n", abs(getDateValue(first_date) - getDateValue(second_date)),
    first_date.day, first_date.month, first_date.year, second_date.day, second_date.month, second_date.year);
    return 0;
}
