#include<bits/stdc++.h>
#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int main(){
    string str;
    cin>>str;
    int count=0;
    int n=str.length();
    int p=str.empty();

    if(n<=100 and p==0){
    sort(str.begin(),str.end());
    for(int i=0;i<n;i++){
            if(str[i]!=str[i+1]){
                count++;
            }
        }

    if(count%2==0){
        cout<<"CHAT WITH HER!";
    }
    else{
        cout<<"IGNORE HIM!";
    }
    }
    return 0;

}
