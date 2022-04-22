#include<stdio.h>
#define N 5

int queue[N];
int font = -1;
int rear = -1;

void enqueue(int x){

if(rear==N-1){
    printf("Overflow");
}

else if(font ==-1  && rear ==-1){
    font = rear =0;
    queue[rear]=x;
}
else{
    rear++;
    queue[rear]=x;
}
}

void dequeue(){

if(font ==-1  && rear ==-1){
    printf("Empty Queue");
}

else if(font==rear){
    font =rear =-1;
}
else{
    font++;
}
}

void display(){
if(font==-1 && rear==-1){
        printf("Empty Queue");
}
else{
    for(int i=font;i<=rear;i++){
        printf("%d",queue[i]);
    }
  }
}

void Peek(){
    if(font==-1 && rear==-1){
        printf("Empty Queue");
    }
    else{
        printf("%d",queue[font]);
    }
}
int main(){
enqueue(2);
enqueue(1);
enqueue(-1);
display();
printf("\n");
Peek();
printf("\n");
dequeue();
display();
printf("\n");
Peek();

}
