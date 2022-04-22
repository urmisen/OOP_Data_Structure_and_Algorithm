#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    long long int n,output;
    cin>>n;

    if(n%2==0){
        output=n/2;
    }
    else{
        output=-(n/2 + 1);
    }

    cout<<output;
    return 0;
}
