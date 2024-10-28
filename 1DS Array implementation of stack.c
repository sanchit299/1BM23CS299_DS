#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void push(int value);
void pop();
void display();

int stack[SIZE];
int top = -1;

int main() {
    int value, choice;

    while(1) {
        printf("\nMenu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Corrected the format specifier

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(int value) {
    if(top == SIZE - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        stack[top] = value;
        printf("Insertion success\n");
    }
}

void pop() {
    if(top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nDeleted %d\n", stack[top]);
        top--;
    }
}

void display() {
    if(top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
