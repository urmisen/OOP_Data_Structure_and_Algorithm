#include<bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;


int main(){
    string str;
    int upp=0;
    int low=0;
    cin>>str;

    for(int i=0;i<str.length();i++){
        if(islower(str[i])){
            low++;
        }
        else{
            upp++;
        }
    }

    if(upp>low){
        for(int j=0;j<str.length();j++){
            str[j]=towupper(str[j]);
        }
    }
    if(low>upp){
        for(int j=0;j<str.length();j++){
            str[j]=towlower(str[j]);
        }
    }
    if(low==upp){
        for(int j=0;j<str.length();j++){
            str[j]=towlower(str[j]);
        }
    }

    cout<<str;

    return 0;
}
