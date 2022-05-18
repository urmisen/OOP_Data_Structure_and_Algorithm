#include<iostream>
using namespace std;


void fn(int i,int fact){
    if(i<1){
        cout<<fact;
        return;
    }

    fn(i-1,fact*i);
}
int main(){
    int n,fact=1;
    cin>>n;
    fn(n,fact);
return 0;
}
