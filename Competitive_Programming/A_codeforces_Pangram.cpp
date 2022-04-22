#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n,count=0;
    string str;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
        str[i]=towupper(str[i]);
    }
    sort(str.begin(),str.end());
    for(int i=0;i<n;i++){
        if(str[i]!=str[i+1]){
            count++;
        }
    }
    if(count==26){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

return 0;

}
