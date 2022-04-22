#include<stdio.h>
#include<cstdlib>

struct node{

    int data;
    struct node *next;
};
struct node *top=0;

void push(int x){
    struct node *newnode;

    newnode=(struct node *) malloc(sizeof(struct node));
//malloc will create a memory block and return a pointer to the starting address of the memory block
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void pop(){
struct node *temp;
temp=top;
if(top ==0){
    printf("Empty Queue");
}
else{
    top=top->next;
    free(temp);
}
}

void display(){
    struct node *temp;
    if(top==0){
        printf("Stack is Empty");
    }
    else{
        temp=top;
        while(temp!=0){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void Peek(){
    if(top==0){
        printf("Empty Stack");
    }
    else{
        printf("%d",top->data);
    }
}

int main(){
push(4);
push(6);
push(1);
display();
printf("\n");
Peek();
printf("\n");
pop();
display();
printf("\n");
Peek();

}

