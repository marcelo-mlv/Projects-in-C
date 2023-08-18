#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node node;
typedef char string[41];

struct node {
    int age;
    int ID;
    string name;
    float salary;
    node* next;
};
node* head;
int numHiredEmployees = 0;
// Keeps track of the amount of employees hired, fired or not

/// Linked List Operations

void createNode() {
    numHiredEmployees++;
    // Auxiliary pointer declaration and initialization
    node* q = (node*)malloc(sizeof(node));
    printf("Type in their name: ");
    fflush(stdin);
    gets(q->name);
    printf("Type in their age: ");
    scanf("%d", &q->age);
    printf("Type in their salary: ");
    scanf("%f", &q->salary);
    q->next = NULL;
    q->ID = numHiredEmployees;

    node* p = head;
    if(p != NULL) {
        while(p->next != NULL)
            p = p->next;
        p->next = q;
    }
    else head = q;
}

void removeNode() {
    printf("Type their name, we'll fire them for sure!\n");
    printf("name: ");
    string name;
    fflush(stdin);
    gets(name);
    node* p = head;
    while(p != NULL && strcmp(p->name, name) != 0)
        p = p->next;
    if(p != NULL) {  // The name was found successfully
        if(p == head)
            head = head->next;
        else {
            node* q = head;
            while(q->next != p)
                q = q->next;
            q->next = p->next;
        }
        free(p);
        printf("\nRemoved successfully!\n\n");
    }
    else // The end of the list was reached, thus a wrong input
        printf("\nThere's no one with this name in the system\n\n");
}

void printList() {
    node *p = head;
    printf("\n=-=-=-= Employees List =-=-=-=\n\n");
    while(p != NULL) {
        printf("Employee #%03d:\n", p->ID);
        printf("\t  name: %s\n", p->name);
        printf("\t   age: %d\n", p->age);
        printf("\tsalary: %.2f\n\n", p->salary);
        p = p->next;
    }
    if(p == head)
        printf("Empty list!\n");
}

/// Terminal

void menu() {
    int endProgram = 0;
    while(endProgram == 0) {
        system("pause");
        system("cls");
        printf("Press:\n");
        printf("1 to hire someone\n");
        printf("2 to fire someone\n");
        printf("3 to print everyone working in the company\n");
        printf("0 to exit the program\n\n");
        int command;
        scanf("%d", &command);
        while(command < 0 || command > 3) {
            printf("Invalid number! Try again: ");
            scanf("%d", &command);
        }
        system("cls");
        switch(command) {
            case 1: createNode(); break;
            case 2: removeNode(); break;
            case 3: printList();  break;
            case 0: endProgram = 1;
            // The while statement above makes sure the default case will never be used
        }
    }
}

int main() {
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("     This is an employee management system     \n");
    printf("            based on linked lists!             \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    menu();
}
