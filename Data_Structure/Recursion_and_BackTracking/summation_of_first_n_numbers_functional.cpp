#include<iostream>
using namespace std;


int fn(int n){
    if(n==0)
        return 0;
    return n+fn(n-1);
}
int main(){
    int n,sum;
    cin>>n;
    sum=fn(n);
    cout<<sum;
return 0;
}

