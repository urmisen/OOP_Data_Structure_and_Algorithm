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

struct node *InsertionAtFirst(struct node* head, int data){
    struct node *ptr,*p;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    // at this point p points to the last node of the circular linked list
    p->next = ptr;
    ptr->next=head;
    head=ptr;

    return head;
    }

void traversal(struct node* head){
    struct node *ptr;
    ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
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
    third->next=head;

    traversal(head);

    head=InsertionAtFirst(head,56);
    printf("\nAfter insertion at first\n");
    traversal(head);

return 0;
}

