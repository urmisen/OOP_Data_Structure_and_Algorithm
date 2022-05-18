void main{
struct node{

    int data
    struct node *next
};

struct node *head, *new_node, *temp
head=0
int choice
while(choice){
new_node=(struct node *) malloc(size_of(struct node))
//malloc will create a memory block and return a pointer to the starting address of the memory block

printf("Enter data");
scanf("%d",&new_node->data)
new_node->next=0

// at beginning when its the only node
if(head==0){
    head=new_node    //fist node creation
    temp=new_node
}

else{
    temp->next=new_node // second node creation
    temp=new_node
}
temp->next=head

printf("Do you want to continue")
scanf("%d",&choice)
}
//display
if(head==0){
    printf("Empty")
}
temp=head
while(temp->next!=head){
    printf("%d",temp->data)
    temp=temp->next
}
printf("%d",temp->data)

getch()
}

