#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_at_begin(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void add_at_end(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL) {
        head = tail = newnode;
    } else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertpos(int x) {
    struct node *newnode, *temp;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        add_at_begin(x);
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("There are less than %d nodes.\n", pos);
                free(newnode);
                return;
            }
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;

        if (newnode->next == NULL) {
            tail = newnode;
        }
    }
}

void printlist() {
    struct node *temp;
    temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
    } else {
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Add at the beginning\n");
        printf("2. Add at the end\n");
        printf("3. Insert at a position\n");
        printf("4. Print the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at the beginning: ");
                scanf("%d", &value);
                add_at_begin(value);
                break;
            case 2:
                printf("Enter value to add at the end: ");
                scanf("%d", &value);
                add_at_end(value);
                break;
            case 3:
                printf("Enter value to insert at a position: ");
                scanf("%d", &value);
                insertpos(value);
                break;
            case 4:
                printlist();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
