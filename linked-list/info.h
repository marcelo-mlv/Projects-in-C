typedef struct node node;
typedef char string[41];

struct node {
    int age;
    int ID;
    string name;
    float salary;
    node* next;
};
