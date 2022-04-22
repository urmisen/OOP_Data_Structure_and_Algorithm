#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;


struct node *create_node(int n){
    struct node *n_node,*temp;
    int i,data;

    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("Memory can not be allocated..!");

    }
    else{
        printf("Enter the value of node 1 :");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
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
    return head;
}

void traversal(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int compare_linked_list(struct node *head1,struct node *head2){

    struct node* l1 =head1;
    struct node* l2 =head2;

    while(l1 || l2){
        if(!l1 || !l2) return 0;
        if(l1->data != l2->data) return 0;
        l1=l1->next;
        l2=l2->next;

    }
    return 1;
}

int main(){
    struct node *head1, *head2;
    int m,n,data,index;
    printf("\n\n Linked List : To create and display Singly Linked List :\n");
    printf("-------------------------------------------------------------\n");

    printf(" Input the number of nodes in first list: ");
    scanf("%d", &n);
    head1= create_node(n);
    printf("\n Data entered in first list : \n");
    traversal();

    printf("\nInput the number of nodes in 2nd list: ");
    scanf("%d", &m);
    head2= create_node(m);
    printf("\n Data entered in 2nd list : \n");
    traversal();
    if(compare_linked_list(head1,head2)){
        printf("linked list matches");
    }
    else{
        printf("linked list don't matches");
    }

return 0;
}

