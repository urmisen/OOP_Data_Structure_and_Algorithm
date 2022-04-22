#include<bits/stdc++.h>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;


int main(){
    int n,t;
    string a;
    cin>>n>>t;
    cin>>a;
    for(int i=0;i<t;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]=='B' && a[j+1]=='G'){

                a[j]='G';
                a[j+1]='B';
                j++;
            }
        }
    }
    cout<<a;


    return 0;
}
