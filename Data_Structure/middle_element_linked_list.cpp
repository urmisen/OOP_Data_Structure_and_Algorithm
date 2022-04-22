#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void createnode(struct node** head,int data){
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=(*head);
    (*head)=new_node;

}

void traversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
}
printf("NULL\n");
}
void Middle_Node(struct node* head){
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;

    if(head!=NULL){
        while(fast_ptr!= NULL && fast_ptr->next !=NULL){
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
        }
        cout<<"The middle element is "<<slow_ptr->data<<endl;
    }
}



int main(){
    struct node* head = NULL;
    int i;

	for (i=5; i>0; i--)
	{
		createnode(&head, i);
		traversal(head);
		Middle_Node(head);
	}

return 0;
}

