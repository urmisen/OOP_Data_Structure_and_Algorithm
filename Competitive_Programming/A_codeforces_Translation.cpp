#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    string s,t,t2;
    char temp;
    int i,j;
    cin>>s>>t;
    int n=s.length();

    for(i=0,j=n-1;i<n/2;i++,j--){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    if(s==t)
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;

}
