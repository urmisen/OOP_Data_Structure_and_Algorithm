#include<stdio.h>
#include<cstdlib>

struct node{

    int data;
    struct node *next;
};
struct node *font=0;
struct node *rear=0;

void enqueue(int x){
    struct node *newnode;

    newnode=(struct node *) malloc(sizeof(struct node));
//malloc will create a memory block and return a pointer to the starting address of the memory block
    newnode->data=x;
    newnode->next=0;
    if(font==0 && rear ==0){
        font=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
struct node *temp;
temp=font;
if(font ==0  && rear ==0){
    printf("Empty Queue");
}
else{
    font=font->next;
    free(temp);
}
}

void display(){
    struct node *temp;
    if(font==0 && rear ==0){
        printf("Queue is Empty");
    }
    else{
        temp=font;
        while(temp!=0){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void Peek(){
    if(font==0 && rear==0){
        printf("Empty Queue");
    }
    else{
        printf("%d",font->data);
    }
}

int main(){
enqueue(2);
enqueue(1);
enqueue(-1);
display();
printf("\n");
Peek();
printf("\n");
dequeue();
display();
printf("\n");
Peek();

}

