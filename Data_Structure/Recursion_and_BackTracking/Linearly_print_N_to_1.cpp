#include<iostream>
using namespace std;

void fn(int i,int n){
    if(i<1){
        return;
    }
    cout<<i<<" ";
    fn(i-1,n);

}
int main(){
    int n;
    cin>>n;
    fn(n,n);
return 0;
}
