#include<iostream>
#include<stdio.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void createnode(struct node **head,int data){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=(*head);
    (*head) = new_node;
}

void traversal(struct node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"\n";
}

struct node* Recursive_Merge(struct node *a, struct node *b){
    struct node* result;
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    if(a->data < b->data){
        result=a;
        result->next=Recursive_Merge(a->next,b);
    }
    else{
        result=b;
        result->next=Recursive_Merge(a,b->next);
    }
    return result;

}

struct node* Merge(struct node *a, struct node *b){
    struct node *p1=a;
    struct node *p2=b;
    struct node *dummy=(struct node *)malloc(sizeof(struct node));
    struct node *p3=dummy;

    while(p1!=NULL && p2!= NULL){
        if(p1->data < p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next= p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

     while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
     }
     while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
     }
    return dummy->next;
}

struct node* Merge_order_one(struct node *l1, struct node *l2){
    struct node* result;
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    if(l1->data > l2->data){
        //swap
        struct node* temp = l1;
        l1=l2;
        l2=temp;
    }
    result = l1;
    while(l1!=NULL && l2 != NULL){
        struct node* tmp = NULL;
        while(l1!= NULL && l1->data <= l2->data){
            tmp = l1;
            l1= l1->next;
        }
        tmp->next=l2;
        //swap
        struct node* temp = l1;
        l1=l2;
        l2=temp;
    }
    return result;
}

int main(){
    struct node *res=NULL;
    struct node *a=NULL;
    struct node *b=NULL;

    createnode(&a,9);
    createnode(&a,7);
    createnode(&a,5);

    createnode(&b,10);
    createnode(&b,8);
    createnode(&b,4);
    createnode(&b,3);

    traversal(a);
    traversal(b);

    res = Merge_order_one(a, b);

    printf("Merged Linked List is: \n");
    traversal(res);
return 0;

}

//Time complexity - O(n+m)
//space complexity - O(n+m)
