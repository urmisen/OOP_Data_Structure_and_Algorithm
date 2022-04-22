#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct node* createnode(int data){
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;

    return n;
}

void traversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
}
}

int main(){
    struct node* head=createnode(7);
    struct node* first=createnode(11);
    struct node* second=createnode(64);
    struct node* third=createnode(41);

    //link the nodes
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=NULL;

    traversal(head);


return 0;
}
