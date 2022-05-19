#include<iostream>
using namespace std;


void fn(int arr[],int i, int n){

    if(i>=(n/2))
        return;
    swap(arr[i],arr[n-i-1]);
    fn(arr,i+1,n);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before Reversal :\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    fn(arr,0,n);
    cout<<"\nAfter Reversal :\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


