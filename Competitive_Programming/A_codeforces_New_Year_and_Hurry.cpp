#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    int count=0,time=0;
    int left=240-k;
    for(int i=1;i<=n;i++){
        time+=i*5;
        if(time<=left){
            count++;
        }
    }
    cout<<count;

    return 0;
}




