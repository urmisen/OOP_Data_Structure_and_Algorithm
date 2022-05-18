#include<iostream>
using namespace std;

void fn(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    fn(i+1,n);

}
int main(){
    int n;
    cin>>n;
    fn(1,n);
return 0;
}
