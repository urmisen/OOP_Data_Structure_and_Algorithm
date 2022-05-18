#include<iostream>
using namespace std;

//Back tracking without using (i+1)

void fn(int i,int n){
    if(i<1){
        return;
    }
    fn(i-1,n);
    cout<<i<<" ";
}
int main(){
    int n;
    cin>>n;
    fn(n,n);
return 0;
}
