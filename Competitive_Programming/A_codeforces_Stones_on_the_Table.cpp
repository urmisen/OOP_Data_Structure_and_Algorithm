#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){

    int n, count=0;
    string str;
    cin>>n;
    cin>>str;
    if(str.length() == n){
    for(int i=0;i<n;i++){
        if(str[i]==str[i+1]){
            count++;
        }
    }
    cout<<count;
    }
    return 0;

}
