#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*st_node;

void createNode(int n){
    struct node *n_node, *temp;
    int data,i;
    st_node = (struct node*)malloc(sizeof(struct node));

    if(st_node == NULL){
        printf("Memory can not be allocated.");
    }
    else{
        printf("Input data for node 1:");
        scanf("%d",&data);
        st_node->data = data;
        st_node->next = NULL;
        temp=st_node;

        for(int i=2;i<=n;i++){
            n_node = (struct node*)malloc(sizeof(struct node));
            if(n_node == NULL){
                printf("Memory can not be allocated.");
                break;
            }
            else{
                printf(" Input data for node %d : ", i);
                scanf(" %d", &data);

                n_node->data = data;      // links the num field of fnNode with num
                n_node->next = NULL; // links the address field of fnNode with NULL

                temp->next = n_node; // links previous node i.e. tmp to the fnNode
                temp = temp ->next;
            }

        }
    }
}

void insertion_at_tail(int data){
    struct node *ptr, *temp;;
    ptr= (struct node*)malloc(sizeof(struct node));
    temp=st_node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ptr->data=data;
    temp->next=ptr;
    ptr->next=NULL;
    }

void traversal(){
    struct node *ptr;
    ptr=st_node;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){

int n,data;
    printf("\n\n Linked List : To create and display Singly Linked List :\n");
    printf("-------------------------------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNode(n);
    printf("\n Data entered in the list : \n");
    traversal();
    printf("\n Input data to insert at the end of the list : ");
    scanf("%d", &data);
    insertion_at_tail(data);
    printf("\n Data, after inserted in the list are : \n");
    traversal();

return 0;
}
