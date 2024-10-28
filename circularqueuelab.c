#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

int isfull() {
    return (rear + 1) % MAX == front;
}

int isempty() {
    return front == -1;
}

void insert(int val) {
    if (isfull()) {
        printf("Overflow\n");
        return;
    }
    if (isempty()) {
        front = 0;  // Initialize front
    }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
}

int delete() {
    if (isempty()) {
        printf("Underflow\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;  // Queue is now empty
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");  // Newline for better readability
}

int main() {
    int choice, val;
    while (1) {
        printf("1 for insert\n2 for delete\n3 for display\n4 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                val = delete();
                if (val != -1) { // Check for underflow before printing
                    printf("Popped = %d\n", val);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
