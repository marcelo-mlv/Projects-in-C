#include <string.h>

#define bool int
#define true 1
#define false 0

typedef struct node node;
typedef char string[41];

struct node {
    int age;
    int ID;
    string name;
    float salary;
    node* next;
};
