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

int dequeue(Queue *q){
int a=-1;
if(q->font ==0  && q->rear ==0){
    printf("Empty Queue");
}

else if(q->font==q->rear){
    q->font =q->rear =-1;
}
else{
    q->font=q->font + 1;
    a=q->arr[q->font];
}
return a;
}

void display(Queue *q){
if(q->font==0 && q->rear==0){
        printf("Empty Queue");
}
else{
    for(int i=q->font;i<=q->rear;i++){
        printf("%d",q->arr[i]);
    }
  }
}

int Peek(Queue *q){
    if(q->font==0 && q->rear==0){
        printf("Empty Queue");
    }
    else{
        printf("%d",q->arr[q->font]);
    }
}

int isEmpty(Queue *q){
    if(q->font==q->rear){
        return 1;
    }
    return 0;
}
int main(){
    struct Queue q;
    q.Size=10;
    q.font=q.rear=0;
    q.arr = (int *) malloc(q.Size*sizeof(int));
    //bfs implementation
    int node;
    int i=1;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d",i);
    visited[i]=1;
    enqueue(&q,i);
    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}
