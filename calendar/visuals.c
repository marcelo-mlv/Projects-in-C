#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"

int main() {
    date first_date;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("    This is a calendar program written in C\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nCalendar display! Just type in a date and we'll show the respective month like in a calendar!\n\n");
    printf("Please submit a date in the format 'dd/mm/yyyy': ");
    scanf("%d/%d/%d", &first_date.day, &first_date.month, &first_date.year);
    while(1) {
        print_calendar(first_date);
        printf("press 'x' to go to the next month\n");
        printf("press 'z' to go to the previous month\n");
        printf("press 'q' to quit\n");
        char tecla, tmp;
        scanf("%c%c", &tmp, &tecla);
        while(tecla != 'x' && tecla != 'z' && tecla != 'q') {
            printf("Invalid key! Try again\n");
            scanf("%c%c", &tmp, &tecla);
        }
        switch(tecla) {
            case 'x':
                first_date.month++;
                if(first_date.month == 13) {
                    first_date.month = 1;
                    first_date.year++;
                }
                break;
            case 'z':
                first_date.month--;
                if(first_date.month == 0) {
                    first_date.month = 12;
                    first_date.year--;
                }
                break;
            case 'q':
                system("cls");
                return 0;
        }
    }
    return 0;
}

