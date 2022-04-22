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

struct node *DeletionFromFirst(struct node* head){
    struct node *temp;
    temp=head;
    head=head->next;

    free(temp);
    return head;
    }

struct node *DeleteAtIndex(struct node* head, int index){
    struct node *temp,*prev;
    temp=head;
    int i=1 ;
    while(i<index){
        prev=temp;
        temp=temp->next;
        i++;
    }

    prev->next=temp->next;
    free(temp);

    return head;
    }

struct node *DeletionFromlast(struct node* head){
    struct node *temp,*prev;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);

    return head;
    }

struct node *DeleteAvalue(struct node* head, int value){
    struct node *temp,*prev;
    temp=head;
    while(temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=0;
    }
    else{
        prev->next=temp->next;
        free(temp);
    }
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

    head=DeletionFromFirst(head);
    printf("Delete first\n");
    traversal(head);

    head=DeleteAtIndex(head,2);
    printf("Delete at index\n");
    traversal(head);

    head=DeletionFromlast(head);
    printf("Delete From last\n");
    traversal(head);

    head=DeleteAvalue(head,11);
    printf("Delete a specific value\n");
    traversal(head);

return 0;
}

