#include<stdio.h>
#include<stdlib.h>

int *arr, size=5;
int front=-1, rear=-1;

void init_queue() {
    arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void enqueue(int *arr, int *front, int *rear, int x) {
    if(*rear == size-1) {
        printf("Queue is full, reallocating memory\n");
        size *= 2;
        arr = (int *)realloc(arr, size*sizeof(int));
        if(arr == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }
    }
    
    if(*front == -1) {
        *front = 0;
    }
    arr[++(*rear)] = x;
}

int dequeue(int *arr, int *front, int *rear) {
    if(*front == -1 || *front > *rear) {
        printf("Queue is empty\n");
        *front = -1;
        *rear = -1;
        return -1;
    }
    else {
        return arr[(*front)++];
    }
}

void display(int *arr, int *front, int *rear) {
    if(*front == -1 || *front > *rear) {
        printf("Queue is Empty\n");
    }
    else {
        printf("The elements in the queue are:-\n");
        for(int i = *front; i <= *rear; i++) {
            printf("%d\n", arr[i]);
        }
    }
}

int main() {
    int item, choice;
    char ch;
    init_queue();
    
    do {
        printf("\nEnter choice:\n");
        printf("0: Enqueue\n");
        printf("1: Dequeue\n");
        printf("2: Display\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:
                printf("Enter the item to be enqueued: ");
                if(scanf("%d", &item) == 1) {
                    enqueue(arr, &front, &rear, item);
                } else {
                    printf("Invalid input\n");
                    while(getchar() != '\n'); // Clear input buffer
                }
                break;
                
            case 1:
                item = dequeue(arr, &front, &rear);
                if(item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
                
            case 2:
                display(arr, &front, &rear);
                break;
                
            default:
                printf("Invalid choice\n");
                break;
        }
        
        printf("Press y to continue: ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');
    
    free(arr);  // Free allocated memory
    return 0;
}