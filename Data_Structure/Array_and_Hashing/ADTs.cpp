//Abstruct Data type is a custom data type which we made by
//defining some variable and methods in it which this custom data type can do.


#include<iostream>
#include<stdio.h>
using namespace std;



struct MyArray{
    int total_size;
    int used_size;
    int *ptr; //points arrays first element
};

void CreateArray(struct MyArray *a,int t_size, int usize){
     //(*a).total_size = t_size;
     //(*a).used_size = usize;
     //(*a).ptr = (int *)malloc(t_size*sizeof(int));
     a->total_size = t_size;
     a->used_size = usize;
     a->ptr = (int *)malloc(t_size*sizeof(int));   //request heap to provide memory to have access to the memory block after the createarray()  method ends
}
void  setArray(struct MyArray *a){
    int n;
    for(int i=0;i<a->used_size;i++){
        printf("Enter element %d :",i+1);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
void  show(struct MyArray *a){
    for(int i=0;i<a->used_size;i++){
        cout<<endl<<(a->ptr)[i];
    }
}
int main(){
    struct  MyArray marks;   //compiler will create a structure and reserve memory for the variables defined in MyArray Structure.
    CreateArray(&marks,10,2); //uses the address of marks which holds the base address and update the variables of the structure
    cout<<"Set Values :"<<endl;
    setArray(&marks);
    cout<<"Show Values :"<<endl;
    show(&marks);
    return 0;
}
