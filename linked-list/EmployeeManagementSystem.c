#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

node* head;
// Amount of current employees
int CurrentEmployees;
// Total amount of employees
int TotalEmployees;

/// Linked List Operations
void createNode() {
    TotalEmployees++;
    CurrentEmployees++;

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
    q->ID = TotalEmployees;

    node* p = head;
    if(p != NULL) {
        while(p->next != NULL)
            p = p->next;
        p->next = q;
    }
    else head = q;
}

void removeNode() {
    if(CurrentEmployees == 0) {
        printf("There's no one here bruv\n");
        return;
    }

    printf("Type their name, we'll fire them for sure!\n");
    printf("name: ");
    string name;
    fflush(stdin);
    gets(name);
    node* p = head;
    while(p != NULL && strcmp(p->name, name) != 0)
        p = p->next;
    if(p != NULL) {  // Name found successfully
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
        CurrentEmployees--;
    }
    else // The end of the list was reached, thus a wrong input
        printf("\nThere's no one with this name in our system :(\n\n");
}

/// Printing function
void printList(node** vector) {
    system("cls");
    printf("\n=-=-=-= Employees List =-=-=-=\n\n");
    int i;
    for(i = 0; i < CurrentEmployees; i++) {
        printf("Employee #%03d:\n", vector[i]->ID);
        printf("\t  name: %s\n", vector[i]->name);
        printf("\t   age: %d\n", vector[i]->age);
        printf("\tsalary: %.2f\n\n", vector[i]->salary);
    }
}

/// Main sorting function
void sortMenu() {
    // If the list is empty:
    if(head == NULL) {
        printf("There's nothing here bruv\n");
        return;
    }

    node** v = (node**)malloc(sizeof(node*) * CurrentEmployees);
    // Node pointer array. It is faster to have each employee attributed to a
    // pointer and sort the array elements instead of comparing by list manipulation
    node *p = head;
    int index = 0;
    while(p != NULL) {
        v[index] = p;
        index++;
        p = p->next;
    }

    int endLoop = 0;
    int selector;
    while(endLoop == 0) {
        system("cls");
        endLoop = 1;
        printf("Press:\n");
        printf("1 to sort based on ID\n");
        printf("2 to sort based on name\n");
        printf("3 to sort based on age\n");
        printf("4 to sort based on salary\n\n");
        int command;
        scanf("%d", &command);
        switch(command) {
            case 1: selector = 1; break;
            case 2: selector = 2; break;
            case 3: selector = 3; break;
            case 4: selector = 4; break;
            default:
                endLoop = 0;
                system("cls");
                printf("Invalid number! Try again\n");
                system("pause");
            // Sorting functions in file sorting.h
        }
    }
    bubbleSort(v, CurrentEmployees, selector);
    system("cls");
    printList(v);
    free(v);
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
        printf("3 to print everyone currently in the company\n");
        printf("0 to exit the program\n\n");
        int command;
        scanf("%d", &command);
        system("cls");
        switch(command) {
            case 1: createNode(); break;
            case 2: removeNode(); break;
            case 3: sortMenu();  break;
            case 0: endProgram = 1; break;
            default:
                system("cls");
                printf("Invalid number! Try again\n");
        }
    }
}

int main() {
    CurrentEmployees = 0;
    TotalEmployees = 0;
    head = NULL;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("     This is an employee management system     \n");
    printf("            based on linked lists!             \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    menu();
}
