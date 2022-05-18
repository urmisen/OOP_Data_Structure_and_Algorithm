#include<stdio.h>
#include<cstdlib>

struct Queue{
int Size;
int font;
int rear;
int *arr;
};
void enqueue(struct Queue *q,int x){

if(q->rear==q->Size - 1){
    printf("Overflow");
}

else if(q->font ==-1  && q->rear ==-1){
    q->font = q->rear =0;
    q->arr[q->rear]=x;
}
else{
    q->rear=q->rear+1;
    q->arr[q->rear]=x;
}
}

void dequeue(Queue *q){

if(q->font ==-1  && q->rear ==-1){
    printf("Empty Queue");
}

else if(q->font==q->rear){
    q->font =q->rear =-1;
}
else{
    q->font=q->font + 1;
}
}

void display(Queue *q){
if(q->font==-1 && q->rear==-1){
        printf("Empty Queue");
}
else{
    for(int i=q->font;i<=q->rear;i++){
        printf("%d",q->arr[i]);
    }
  }
}

void Peek(Queue *q){
    if(q->font==-1 && q->rear==-1){
        printf("Empty Queue");
    }
    else{
        printf("%d",q->arr[q->font]);
    }
}
int main(){
    struct Queue q;
    q.Size=10;
    q.font=q.rear=-1;
    q.arr = (int *) malloc(q.Size*sizeof(int));
    enqueue(&q,2);
    enqueue(&q,1);
    enqueue(&q,-1);
    display(&q);

}
