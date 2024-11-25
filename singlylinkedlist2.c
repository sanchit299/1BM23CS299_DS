#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *deleteFirst(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteByValue(struct Node *head, int value) {
    if (head == NULL) return NULL;
    struct Node *p = head;
    struct Node *q = head->next;

    if (head->data == value) {
        head = deleteFirst(head);
        return head;
    }

    while (q != NULL && q->data != value) {
        p = p->next;
        q = q->next;
    }

    if (q != NULL && q->data == value) {
        p->next = q->next;
        free(q);
    } else {
        printf("Value not found\n");
    }

    return head;
}

void create(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node *deleteAtLast(struct Node *head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

void linkedListDisplay(struct Node *ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node *head = NULL;
    int choice, val;
    while (1) {
        printf("1: Insert at end\n");
        printf("2: Delete at first\n");
        printf("3: Delete at last\n");
        printf("4: Delete by value\n");
        printf("5: Display\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                create(&head, val);
                break;
            case 2:
                head = deleteFirst(head);
                break;
            case 3:
                head = deleteAtLast(head);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                head = deleteByValue(head, val);
                break;
            case 5:
                linkedListDisplay(head);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

