#include<bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;


int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int total=0;

    for(int i=1;i<=w;i++){
        total+=k*i;
    }
    int need= total-n;
    if(need<0){
        cout<<"0";
    }
    else{
    cout<<need;
    }
    return 0;
}
