
void main{
struct node{

    int data
    struct node *next
};

struct node *head, *new_node, *temp, *prev, *next_node
head=0
int choice,pos,i=1


//***** delete from the beginning *****

temp=head
head=head->next
free(temp)

// ***** delete from the end *****


temp=head

while(temp->next!=0){
    prev=temp
    temp=temp->next
}

if(temp==head){
    head=0;
}
else{
    prev->next=0
}
free(temp)
}

//delete from any position
printf("enter the position")
scanf("%d",&pos)
int i==1
if(pos>count)
{
    Printf("Invalid Position")
}

else{
    temp=head
    while(i<pos){
        prev=temp
        temp=temp->next
        i++
    }

    prev-next=temp->next
    free(temp)
}









