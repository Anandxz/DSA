#include <stdio.h>
#include <stdlib.h>

int item, arr[5], size = 5;
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % size == front) {
        printf("queue is full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }
}

int dequeue() {
    if (front == -1) {
        printf("queue is empty\n");
        return 0;
    } else {
        int item = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return item;
    }
}

void display() {
    if (front == -1) {
        printf("queue is empty\n");
        return;
    }
    printf("the elements in the queue are:\n");
    int i = front;
    while (i != rear) {
        printf("%d\n", arr[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", arr[i]);
}

int main() {
    int x;
    char ch;
    do {
        printf("enter 0 for enqueue or 1 for dequeue or 2 for display: ");
        scanf("%d", &x);
        switch (x) {
            case 0:
                printf("enter the number to be enqueued: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 1:
                printf("%d\n", dequeue());
                break;
            case 2:
                display();
                break;
            default:
                printf("wrong choice\n");
                break;
        }
        printf("press y to continue: ");
        scanf(" %c", &ch);
    } while (ch == 'y');
    return 0;
}