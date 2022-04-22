#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    long long n,m,i,max=0,x=0 ;
    cin>>n>>m;
    int *arr=(int *)malloc(sizeof(int)*n+1);
    for(i=1;i<=n;i++){
        arr[i]=0;
    }

    for(i=0;i<m;i++){
        long long a,b,k;
        cin>>a>>b>>k;
        arr[a]+=k;
        if(b+1<=n){
            arr[b+1]-=k;
        }
    }
    for(i=1;i<=n;i++){
        x+=arr[i];
        if(max<x){
            max=x;
        }
    }
    cout<<max;
    return 0;
}


