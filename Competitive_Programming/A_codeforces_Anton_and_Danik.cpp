#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n,A_count=0,D_count=0;
    string s;
    cin>>n;
    cin>>s;

    for(int i=0;i<n;i++){
        if(isupper(s[i])==1){
            if(s[i]=='A'){
                A_count++;
            }
            if(s[i]=='D'){
                D_count++;
            }
    }
    }

    if(A_count>D_count){
        cout<<"Anton";
    }
    if(A_count<D_count){
        cout<<"Danik";
    }
    if(A_count==D_count){
        cout<<"Friendship";
    }

return 0;

}
