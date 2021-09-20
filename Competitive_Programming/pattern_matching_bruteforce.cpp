#include<bits/stdc++.h>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int pattern_matching(string S, string P){
    int LS = S.length();
    int LP = P.length();
    int MAX = LS-LP+1;

    for(int i=0;i<MAX;i++){
        int flag=1;
        for(int j=0;j<LP;j++){
            if(P[j]!= S[i+j-1]){
                flag = 0;
            }
        }
        if(flag==1){
            return i;
        }

    }
    return 0;
}

int main(){
    string str,pt;
    cout<<"enter the main string : \n";
    cin>>str;

    cout<<"enter the pattern string : \n";
    cin>>pt;

    int output= pattern_matching(str,pt);

    if(output!=0){
        cout<<"Pattern matched from "<<output<<"th position. \n";
    }
    else{
        cout<<"Pattern not matched. ";
    }


    return 0;
}

