// Implemenatation of queue using array

#include<stdio.h>
#include<stdlib.h>
   int item,arr[5],size=5;
   int front=-1,rear=-1;

   void enqueue(int x){
    if((rear+1)%size==front){     // or we can use rear==size-1
        printf("Queue is full\n");
    }
    else{
        if(front==-1){
            //printf("Queue is empty");
            front=rear=0;
            rear=(rear+1)%size;
            arr[rear]=x;
        }
    }
   }

   int dequeue(){
    if (front==-1)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
       int item=arr[front];
       if (front==rear)
       {
         front=rear=-1;
       }
       else
       {
        front=(front+1)%size;
       }
       return item;
       }
}

     int display(){
        if (front==-1)
        {
            printf("Queue is empty");
            return 0;
        }
        printf("The element the the array");
        int i=front;
        while (i!=rear)
        {
            printf("%d\t",arr[i]);
            i=(i+1)%size;
        }
        printf("%d\t",arr[i]);
                   }
        
int main(){
    int x;
    char ch;
    do
    {
        printf("Enter o for ENque 1 for Dequeue and 2 for Dispaly");
        scanf("%c",&x);
        switch(x){
            case 0:
            printf("Enter the no to insert:\n");
            scanf("%d",&item);
            enqueue(item);
            break;
            case 1:
            printf("%d",dequeue());
            break;
            case 3:
            display();
            break;
            default :
            printf("Invalid choice");
            break;
        }
        printf("\nDo you want to continue? (y/n)");
        scanf("%c",&ch);
    } while (ch=='y');
    return 0;
    
}