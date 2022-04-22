#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    string str1,str2;
    char out;
    int n;

    cin>>str1>>str2;
    n=str1.length();
    for(int i=0;i<n;i++){
        if(str1[i]==str2[i]){
            cout<<"0";
        }
        else{
            cout<<"1";
        }
    }

    return 0;
}
