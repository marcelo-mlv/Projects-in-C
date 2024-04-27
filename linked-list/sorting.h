#include <string.h>
#include "info.h"


/// Bubble sort by ID
void bubbleSortID(node **v, int n) {
    int i, j;
    node *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j]->ID > v[j + 1]->ID) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

/// Bubble sort by salary
void bubbleSortSal(node **v, int n) {
    int i, j;
    node *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j]->salary > v[j + 1]->salary) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

/// Bubble sort by age
void bubbleSortAge(node **v, int n) {
    int i, j;
    node *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j]->age > v[j + 1]->age) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

/// Bubble sort by name
void bubbleSortName(node **v, int n) {
    int i, j;
    node *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(v[j]->name, v[j + 1]->name) > 0) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
