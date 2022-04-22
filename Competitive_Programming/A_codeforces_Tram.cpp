#include<bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;


int main(){
    int n,a,b,capacity;
    cin>>n;
    int arr[n];
    int total=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        total=total-a+b;
        arr[i]=total;
    }

    for(int i=1;i<n;i++){
        if(arr[0]<arr[i]){
            arr[0]=arr[i];
        }

    }
    capacity=arr[0];

    cout<<capacity;





    return 0;
}
