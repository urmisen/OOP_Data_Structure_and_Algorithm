#include<bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;


int main(){
    int a,b,i;
    int count=0;
    cin>>a>>b;

    for(i=1;;i++){
        a*=3;
        b*=2;
        if(a>b)break;
    }
    cout<<i;
    return 0;
}
