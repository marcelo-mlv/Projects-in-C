#include "info.h"


bool conditional(node **v, int index, int selector) {
    switch(selector) {
        case 1: return v[index]->ID > v[index+1]->ID ? true : false;
        case 2: return strcmp(v[index]->name, v[index+1]->name) > 0 ? true : false;
        case 3: return v[index]->age > v[index + 1]->age ? true : false;
        case 4: return v[index]->salary > v[index + 1]->salary ? true : false;
    }
}

void bubbleSort(node **v, int n, int selector) {
    int i, j;
    node *temp;
    bool over = false;
    for (i = 0; i < n - 1 && !over; i++) {
        over = true;
        for (j = 0; j < n - i - 1; j++)
            if (conditional(v, j, selector)) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                over = false;
            }
    }
}
