#include<stdio.h>
#include<stdlib.h>

int *arr, size=5;
int top=-1;

void init_stack() {  // Fixed function name typo
    arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL) {  // Fixed comparison operator
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void push(int *arr, int *top, int x) {
    if(*top == size-1) {
        printf("Stack is full, reallocating memory\n");
        size *= 2;
        arr = (int *)realloc(arr, size*sizeof(int));  // Fixed realloc typo
        if(arr == NULL) {  // Fixed comparison operator
            printf("Memory reallocation failed\n");
            exit(1);
        }
    }
    arr[++(*top)] = x;
}

int pop(int *arr, int *top) {  // Changed return type to int
    if (*top == -1) {  // Fixed comparison operator
        printf("Stack is empty\n");
        return -1;
    }
    else {
        return arr[(*top)--];
    }
}

void display(int *arr, int *top) {
    if (*top == -1) {  // Fixed comparison operator
        printf("Stack is Empty\n");
    }
    else {
        printf("The elements in the stack are:-\n");  // Added semicolon and newline
        for (int i = 0; i <= *top; i++)  // Fixed loop condition
        {
            printf("%d\n", arr[i]);
        }
    }
}

int main() {
    int item, choice;  // Fixed variable names
    char ch;
    init_stack();  // Fixed function name
    
    do {
        printf("Enter 0,1,2 for push, pop, display: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Enter the item to be pushed: ");
                if(scanf("%d", &item) == 1) {  // Fixed scanf check
                    push(arr, &top, item);
                } else {
                    printf("Invalid input\n");
                    while(getchar() != '\n');  // Clear input buffer
                }
                break;
                
            case 1:
                item = pop(arr, &top);
                if(item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
                
            case 2:
                display(arr, &top);
                break;
                
            default:
                printf("Invalid choice\n");
                break;
        }
        
        printf("Press y to continue: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    
    free(arr);  // Free allocated memory
    return 0;
}