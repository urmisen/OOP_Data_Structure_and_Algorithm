
void main{
struct node{

    int data
    struct node *next
};

struct node *head, *new_node, *temp
head=0
int choice,pos,i=1


//***** Insert at the beginning *****

new_node=(struct node *) malloc(size_of(struct node))
//malloc will create a memory block and return a pointer to the starting address of the memory block

printf("Enter data");
scanf("%d",&new_node->data)

new_node->next=head
head=new_node

//insert at the end
new_node=(struct node *) malloc(size_of(struct node))
//malloc will create a memory block and return a pointer to the starting address of the memory block

printf("Enter data");
scanf("%d",&new_node->data)
new_node->next=0

temp=head

while(temp->next!=0){
    temp=temp->next
}

temp->next=new_node

}

//inset at any position
printf("enter the position")
scanf("%d",&pos)
if(pos>count)
{
    Printf("Invalid Position")
}

else{
    temp=head
    while(i<pos){
        temp=temp->next
        i++
    }
    new_node=(struct node *) malloc(size_of(struct node))
    printf("Enter data");
    scanf("%d",&new_node->data)
    new_node->next=temp->next
    temp->next=new_node
}


















