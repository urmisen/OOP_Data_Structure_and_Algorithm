//unsorted array
#include<iostream>
using namespace std;

void display(int arr[], int n){
    //Traversal
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int linear_search(int arr[],int size,int ele){
    for(int i=0;i<size;i++){
        if(arr[i]==ele){
            return i;
        }
    }
    return -1;
}


using namespace std;
 int main(){
    int arr[] = {7,8,12,27,88,4,87,34,9,122,90},ele;
    int size = sizeof(arr)/sizeof(int);
    cout<<"Enter the element to be found :";
    cin>>ele;

    int searchInd = linear_search(arr,size,ele);
    cout<<"\nThe element "<<ele<<" is founded in Index "<<searchInd<<endl;
 return 0;
 }
