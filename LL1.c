#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;

void insertbegin(int element) {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->link = NULL;
    
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->link = head;
        head = new_node;
    }
}

void insertend(int element) {
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->link = NULL;
    
    if (head == NULL) {
        head = new_node;
    } else {
        temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void delete() {
    struct node *temp;
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        temp = head;
        printf("Deleted element: %d\n", head->data);
        head = temp->link;
        free(temp);
    }
}

void display() {
    struct node *temp;
    temp = head;
    
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}

int main() {
    char ch;
    int x, element;
    
    do {
        printf("Enter 0 to insert at beginning, 1 to insert at end, 2 to delete, 3 to display: ");
        scanf("%d", &x);
        switch (x) {
            case 0:
                printf("Enter element to add at the beginning: ");
                scanf("%d", &element);
                insertbegin(element);
                break;
            case 1:
                printf("Enter element to add at the end: ");
                scanf("%d", &element);
                insertend(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("Press 'y' to continue: ");
        scanf(" %c", &ch); // Notice the space before %c to consume the newline character
    } while (ch == 'y');
    
    return 0;
}