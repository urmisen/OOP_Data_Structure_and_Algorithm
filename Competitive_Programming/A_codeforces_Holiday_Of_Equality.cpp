#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    if(min==0){
        int diff=max-min;
        for(int i=0;i<n;i++){
            if(diff!=arr[i]){
                sum+=abs(arr[i]-diff);
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
        if(max!=arr[i]){
            sum+=abs(arr[i]-max);
        }
    }
    }
    cout<<sum;

    return 0;
}




