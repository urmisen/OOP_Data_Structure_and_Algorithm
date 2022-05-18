#include<iostream>
using namespace std;


int fn(int n){
    if(n==0)
        return 1;
    return n*fn(n-1);
}
int main(){
    int n,fact;
    cin>>n;
    fact=fn(n);
    cout<<fact;
return 0;
}

