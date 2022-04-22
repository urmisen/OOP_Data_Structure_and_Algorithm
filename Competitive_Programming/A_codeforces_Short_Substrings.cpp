#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;


int main(){
    int t;
    cin>>t;
    string b,a;

    while(t--){
        cin>>b;
        int n=b.length();
        if(n==2){
            for(int i=0;i<n;i++){
                cout<<b[i];
            }
            cout<<endl;
        }
        else{
            cout<<b[0];
            for(int i=1;i<n;i+=2){
                    cout<<b[i];
                }
            cout<<endl;
            }
    }
    return 0;
}




