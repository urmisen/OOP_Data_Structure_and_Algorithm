#include<iostream>
using namespace std;

void display(int arr[], int n){
    //Traversal
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void indDeletion(int arr[],int size,int capacity,int index){
    if(index>=capacity){
        return;
    }
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }

}
using namespace std;
 int main(){
    int arr[100] = {7,8,12,27,88};
    int size=5,element = 45, index=1;
    display(arr,size);
    indDeletion(arr,size,100,index);
    size-=1;
    cout<<"\n";
    display(arr,size);
 return 0;
 }
