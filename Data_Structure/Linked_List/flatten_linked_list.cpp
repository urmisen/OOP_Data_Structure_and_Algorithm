#include<iostream>
#include<stdio.h>
using namespace std;

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

struct node{
    int data;
    struct node *next;
    struct node *bottom;
};
void createnode(struct node **head,int data){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));

    new_node->data=data;
    new_node->next=NULL;
    new_node->bottom= (*head);
    (*head)=new_node;

}

void createVerticalList(struct node **head, int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        createnode(head, arr[i]);
    }
}

struct node* sortedMerge(struct node* a, struct node* b)
{
    struct node* p3 =  new node();
    struct node* p1=a;
    struct node* p2=b;
    struct node* dummy =p3;

    while( p1!= NULL && p2!= NULL){
         if(p1->data < p2->data){
            p3->bottom = p1;
            p1=p1->bottom;
         }

         else{
            p3->bottom = p2;
            p2=p2->bottom;
         }
         p3=p3->bottom;
    }

    if(p1) p3 ->bottom = p1;
    else p3 -> bottom =  p2;
    return dummy->bottom;
}

// Recursive function to flatten and sort a given list
struct node* flatten(struct node* head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }

    head->next = flatten(head->next);

    head = sortedMerge(head,head->next);

    return head;
}
void traversal(struct node *ptr)
{
    while (ptr)
    {
        cout<<" -> "<<ptr->data;
        ptr = ptr->bottom;
    }
    cout<<" -> NULL";
}


int main(){
    struct node *head =NULL;

    int arr1[] = { 8, 6, 4, 1 };
    int arr2[] = { 7, 3, 2 };
    int arr3[] = { 9, 5 };
    int arr4[] = { 12, 11, 10 };

    createVerticalList(&(head), arr1, SIZE(arr1));
    createVerticalList(&(head->next), arr2, SIZE(arr2));
    createVerticalList(&(head->next->next), arr3, SIZE(arr3));
    createVerticalList(&(head->next->next->next), arr4, SIZE(arr4));

    // flatten the list
    flatten(head);

    // print the flattened and sorted linked list
    traversal(head);

return 0;
}
