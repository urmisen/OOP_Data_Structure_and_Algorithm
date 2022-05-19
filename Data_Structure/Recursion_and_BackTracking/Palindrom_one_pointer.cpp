#include<iostream>
using namespace std;


bool fn(string &str,int i, int n){

    if(i>=(n/2))
        return true;
    if(str[i]!=str[n-i-1])
        return false;

    return fn(str,i+1,n);
}
int main(){
    int n;
    string str;
    cin>>str;
    n = str.length();

    bool ans = fn(str,0,n);

    if(ans ==1) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}



