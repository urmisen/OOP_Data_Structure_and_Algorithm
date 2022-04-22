#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int Pi[n];
    for(int i=0;i<n;i++){
        cin>>Pi[i];
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(Pi[i]==j){
                cout<<i+1<<" ";
            }
        }
    }
    return 0;
}

