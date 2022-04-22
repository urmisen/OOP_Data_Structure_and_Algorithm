//array must be sorted
#include<iostream>
using namespace std;

void display(int arr[], int n){
    //Traversal
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int binarySearch(int arr[],int Size,int ele){
    int low,mid,high;
    low=0;
    high = Size-1;
    //searching starts
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==ele){
            return mid;
        }
        if(arr[mid]<ele){
            low = mid + 1;
        }
        else{
            high = mid - 1;
            }
        }
        //searching elds
        return -1;
}


using namespace std;
 int main(){
    int arr[] = {7,8,12,27,34,88,90,122,159},ele;
    int Size = sizeof(arr)/sizeof(int);
    cout<<Size;
    cout<<"Enter the element t3o be found : ";
    cin>>ele;

    int searchInd = binarySearch(arr,Size,ele);
    cout<<"\nThe element "<<ele<<" is founded in Index "<<searchInd<<endl;
 return 0;
 }
