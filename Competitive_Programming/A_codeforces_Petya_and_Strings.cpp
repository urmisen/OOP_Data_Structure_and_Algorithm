#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){

    string str1,str2;
    cin>>str1>>str2;

    int len1 = str1.length();
    int len2 = str2.length();

    if(len1==len2){
        for(int i=0;i<len1;i++){
            str1[i]=towlower(str1[i]);
            str2[i]=towlower(str2[i]);
        }

        if(str1 == str2){
            cout<<"0\n";
        }
        else{
            for(int j=0;j<len1;j++){
                if(str1[j]<str2[j]){
                    cout<<"-1\n";
                    break;
                }
                if(str1[j]>str2[j]){
                    cout<<"1\n";
                    break;
                }
            }
        }
    }

    return 0;

}
