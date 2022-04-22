#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n],Max=0,Min=101,maxi,mini,sec;


    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>Max){
            Max=arr[i];
            maxi=i;
        }
        if(arr[i]<=Min){
            Min=arr[i];
            mini=i;
        }
        }
    if(mini<maxi){
        mini++;
    }
    sec=maxi+(n-1)-mini;
    cout<<sec;
    return 0;
}


