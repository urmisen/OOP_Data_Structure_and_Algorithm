#include<stdio.h>
#define N 5

int stack[N];
int top = -1;

void push(int x){

if(top==N-1){
    printf("Overflow");
}

else{
    top++;
    stack[top]=x;
}
}

void pop(){
int item;
if(top == -1){
    printf("Empty stack");
}
else{
    item=stack[top]; //poped item
    top--;
}
}

void display(){
if(top==-1){
        printf("Empty Queue");
}
else{
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
  }
}

void Peek(){
    if(top==-1){
        printf("Empty Queue");
    }
    else{
        printf("%d",stack[top]);
    }
}
int main(){
push(4);
push(6);
push(1);
display();
printf("\n");
Peek();
printf("\n");
pop();
display();
printf("\n");
Peek();

}
