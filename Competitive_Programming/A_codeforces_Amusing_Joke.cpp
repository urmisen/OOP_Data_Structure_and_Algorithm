#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    string str1,str2,str3;
    cin>>str1>>str2>>str3;
    string str4;
    str4=str1+str2;
    sort(str3.begin(),str3.end());
    sort(str4.begin(),str4.end());


    if(str3==str4){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}



