#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

int is_empty() {
    return front == -1 || front > rear;
}

int is_full() {
    return rear == MAX - 1;
}

void insert(int value) {
    if (is_full()) {
        printf("Queue overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = value;
        printf("Inserted %d\n", value);
    }
}

void delete() {
    if (is_empty()) {
        printf("Queue underflow! Cannot delete\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        front++;
        if (is_empty()) {
            front = rear = -1;
        }
    }
}

void display() {
    if (is_empty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
