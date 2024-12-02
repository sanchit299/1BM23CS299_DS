#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    };

struct node*head = NULL;
void append(struct node* head  ,  int data)
{
    struct node* new_node = (struct node *)malloc(sizeof(struct node));
    new_node ->data = data;
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node*temp = head;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next =new_node ;

    }


}

void sorting()
{
    struct node *ptr, *cpt;
    int temp;

    if (head == NULL || head->next == NULL) {
        return;
    }

    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        for (cpt = ptr->next; cpt != NULL; cpt = cpt->next) {
            if (ptr->data > cpt->data) {
                temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
        }
    }
}


void concat(struct node *head1 , struct node *head2)
{
struct node * ptr = NULL;
ptr = head1;
while(ptr->next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr->next = head2;



}

void reverse(struct node** head) {
    struct node* prev = NULL;
    struct node* curr = *head;
    struct node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}




void display()
{
    struct node * temp;
    temp = head ;
    if (temp != NULL)
    {
        printf("list is empty");
    }
    else {
        while (temp != NULL)
        {
            printf("%d ->",temp->data);

        }
    }
}

int main() {
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    int choice, data;

    while (1) {
        printf("1 for append to list1\n");
        printf("2 for append to list2\n");
        printf("3 for concatenation\n");
        printf("4 for display list1\n");
        printf("5 for display list2\n");
        printf("6 for reverse list1\n");
        printf("7 for reverse list2\n");
        printf("8 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Add to list1: ");
                scanf("%d", &data);
                append(&list1, data);
                break;
            case 2:
                printf("Add to list2: ");
                scanf("%d", &data);
                append(&list2, data);
                break;
            case 3:
                concat(&list1, list2);
                break;
            case 4:
                printf("List1: ");
                display(list1);
                break;
            case 5:
                printf("List2: ");
                display(list2);
                break;
            case 6:
                printf("Reversing list1...\n");
                reverse(&list1);
                break;
            case 7:
                printf("Reversing list2...\n");
                reverse(&list2);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
