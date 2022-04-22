#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n,p,q,arr[100];
    int count=0;
    cin>>n>>p;

    for(int i=0;i<p;i++){
        cin>>arr[i];
    }
    cin>>q;
    for(int i=p;i<p+q;i++){
        cin>>arr[i];
    }
    sort(arr,arr+(p+q));
    for(int i=0;i<p+q;i++){
        if(arr[i]!=arr[i+1]){
            count++;
        }
    }
    if(count==n){
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }
    return 0;
}
