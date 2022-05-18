#include<stdio.h>
#include<cstdlib>

struct Stack{
int Size;
int top;
int *arr;
};
void push(struct Stack *q,int x){

if(q->top==q->Size - 1){
    printf("Overflow");
}
else{
    q->top=q->top+1;
    q->arr[q->top]=x;
}
}

void pop(Stack *q){

if(q->top ==-1){
    printf("Empty Stack");
}
else{
    q->top=q->top - 1;
}
}

void display(Stack *q){
if(q->top==-1){
        printf("Empty Stack");
}
else{
    for(int i=q->top;i>=0;i--){
        printf("%d",q->arr[i]);
    }
  }
}

void Peek(Stack *q){
    if(q->top==-1){
        printf("Empty Stack");
    }
    else{
        printf("%d",q->arr[q->top]);
    }
}
int main(){
    struct Stack q;
    q.Size=10;
    q.top = -1;
    q.arr = (int *) malloc(q.Size*sizeof(int));
    push(&q,4);
    push(&q,6);
    push(&q,1);
    display(&q);
    printf("\n");
    Peek(&q);
    printf("\n");
    pop(&q);
    display(&q);
    printf("\n");
    Peek(&q);

}
