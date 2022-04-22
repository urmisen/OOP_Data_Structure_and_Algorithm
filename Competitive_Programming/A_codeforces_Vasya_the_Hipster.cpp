#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int a,b;
    cin>>a>>b;
    int diff_socks;
    int same_socks;

    if(a==b){
        diff_socks=a;
        same_socks=0;
    }
    if(a>b){
        diff_socks=b;
        same_socks=(a-b)/2;
    }
    if(a<b){
        diff_socks=a;
        same_socks=(b-a)/2;
    }
    cout<<diff_socks<<" "<<same_socks;
    return 0;
}



