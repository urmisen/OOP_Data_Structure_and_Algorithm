void main{
struct node{

    int data
    struct node *next
};

struct node *tail, *new_node
head=0
int choice
while(choice){
new_node=(struct node *) malloc(size_of(struct node))
//malloc will create a memory block and return a pointer to the starting address of the memory block

printf("Enter data");
scanf("%d",&new_node->data)
new_node->next=0

//at the beginning
if(tail==0){
    tail=new_node
    tail->next=new_node
}
else{
    new_node->next=taoil->next
    tail->next=new_node
}

//at the end
if(tail==0){
    tail=new_node
    tail->next=new_node
}
else{
    new_node->next=tail->next
    tail->next=new_node
    tail=new_node
}


//at any position
int pos,i=1

printf("enter the position")
scanf("%d",&pos)
i=getlength()
if(pos<0 || pos>l)
{
    Printf("Invalid Position")
}

else if(pos==1){
    insetbeg()
}

else{
    new_node=(struct node *) malloc(size_of(struct node))
    //malloc will create a memory block and return a pointer to the starting address of the memory block

    printf("Enter data");
    scanf("%d",&new_node->data)
    new_node->next=0

    temp=tail->next
    while(i<pos-1){
        temp=temp->next
        i++
    }
    new_node=(struct node *) malloc(size_of(struct node))
    printf("Enter data");
    scanf("%d",&new_node->data)
    new_node->next=temp->next
    temp->next=new_node

}
