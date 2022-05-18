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

struct node *InsertionAtFirst(struct node* head, int data){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;

    return ptr;
    }

struct node *InsertionInBetween(struct node* head, int data, int index){
    struct node *ptr, *temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    temp=head;
    int i=1 ;
    while(i<index){
        temp=temp->next;
        i++;
    }
    ptr->data=data;
    ptr->next=temp->next;
    temp->next=ptr;

    return head;
    }

struct node *InsertionAtlast(struct node* head, int data){
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ptr->data=data;
    temp->next=ptr;
    ptr->next=NULL;

    return head;
    }

struct node *InsertionAfterNode(struct node* head,struct node* prevnode, int data){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));

    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;

    return head;
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

    head=InsertionAfterNode(head,second,35);
    printf("Insertion after a specific node\n");
    traversal(head);

    head=InsertionAtFirst(head,56);
    printf("After insertion at first\n");
    traversal(head);

    head=InsertionInBetween(head,78,2);
    printf("After insertion in between\n");
    traversal(head);

    head=InsertionAtlast(head,98);
    printf("After insertion at end\n");
    traversal(head);

return 0;
}

