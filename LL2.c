#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;
// insert from begining::
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
printf("\n");
    }
}
// insert from end::
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
printf("\n");
    }
}
// insert at any piont::
void insert_any_place(int element ,int position){
struct node *new_node,*temp;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=element;
new_node->link=NULL;
temp=head;
if(position==1){
new_node->link=head;
head=new_node;
}
else{
for(int i=1;i<position-1 && temp !=NULL;i++){
temp=temp->link;
}
new_node->link=temp->link;
temp->link=new_node;

}}
// delete from begining::
void delete_first() {
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
// delete from end::
void delete_end(){
struct node * temp;
temp=head;
if(head==NULL){
printf("empty lnk list\n");
}
else{
while(temp->link->link!=NULL){
temp=temp->link;
}
printf("deleted element are::%d\n",temp->link->data);
free(temp->link);
temp->link=NULL;
}
}
// delet at any places::
void delet_any_position(){
struct node *current_node,*priviouds_node;
current_node=head;
priviouds_node=NULL;
int x;
printf("give deleted position::\n");
scanf("%d",&x);
if(x==1){
head=head->link;
printf("deleted element are::\n%d",current_node->data);
free(current_node);
}
else{
      for(int i=1;i<x && current_node!=NULL;i++){
priviouds_node=current_node;
current_node=current_node->link;}
if(current_node==NULL){
printf("node is not avalabel");
}
else{
priviouds_node->link=current_node->link;
printf("deleted element are::%d\n",current_node->data);
free(current_node);
}
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
    int x, element,position;
    
    do {
        printf("ENTRE 0 TO INSERT BEGIN::\n");
        printf("ENTRE 1 TO INSERT END::\n");
        printf("ENTRE 2 TO INSERT ANY WHERE::\n");
        printf("ENTRE 3 TO DELETE BEGIN::\n");
        printf("ENTER 4 TO DELET END::\n");
        printf("ENTRE 5 TO DELETE ANY WHERE::\n");
        printf("ENTRE 6 TO DISPALY::\n");
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
            case 3:
                delete_first();
                break;
            case 6:
                display();
                break;
            case 2:
                printf("ENTRE INDEX TO INSERT ELEMENT AND GIVE ELEMENT");
            scanf("%d %d",&position, &element);
            insert_any_place(element,position);
            break;
            case 4:
            delete_end();
            break;
           case 5:
           delet_any_position();
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
