#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create_linked_list(int data_list[], int n) {
    for (int i = 0; i < n; i++) {
        insert_at_end(data_list[i]);
    }
}

void insert_at_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display_linked_list() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;
    int data_list[] = {10, 20, 30};
    int n = sizeof(data_list) / sizeof(data_list[0]);

    create_linked_list(data_list, n);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Display linked list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_linked_list();
                break;
            case 2:
                printf("Enter a value to insert at the beginning: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 3:
                printf("Enter a value to insert at the end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
