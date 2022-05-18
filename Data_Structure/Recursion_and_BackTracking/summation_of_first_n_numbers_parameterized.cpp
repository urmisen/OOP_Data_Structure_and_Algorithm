#include<iostream>
using namespace std;


void fn(int i,int sum){
    if(i<1){
        cout<<sum;
        return;
    }

    fn(i-1,sum+i);
}
int main(){
    int n,sum=0;
    cin>>n;
    fn(n,sum);
return 0;
}
