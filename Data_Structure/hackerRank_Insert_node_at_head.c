#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
 }*head;
void create_node(int n){
    struct node *n_node,*temp;
    int data,i;
    head= (struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("Memory can not be allocated..!");
    }
    else{

        printf("Enter the value of node 1 :");
        scanf("%d",&data);
        head->data=data;
        head->next= NULL;
        temp=head;

        for(i=2;i<=n;i++){
            n_node=(struct node*)malloc(sizeof(struct node));
            if(n_node==NULL){
                printf("Memory can not be allocated..!");
                break;
            }
            printf("Enter the value of node %d :",i);
            scanf("%d",&data);

            n_node->data=data;
            n_node->next=NULL;

            temp->next=n_node;
            temp=temp->next;
        }
    }
}

void traversal(){

    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
}
}

void insertion_at_head(int data){
    struct node *ptr, *temp;
    ptr= (struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;

}


int main(){

    int n,data;
    printf("\n\n Linked List : To create and display Singly Linked List :\n");
    printf("-------------------------------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    create_node(n);
    printf("\n Data entered in the list : \n");
    traversal();
    printf("\n Input data to insert at the end of the list : ");
    scanf("%d", &data);
    insertion_at_head(data);
    printf("\n Data, after inserted in the list are : \n");
    traversal();

return 0;
}
