#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int ans=n/100;
    int left=n%100;

    ans+=left/20;
    left=left%20;

    ans+=left/10;
    left=left%10;

    ans+=left/5;
    left=left%5;

    ans+=left/1;

    cout<<ans;
    return 0;
}



