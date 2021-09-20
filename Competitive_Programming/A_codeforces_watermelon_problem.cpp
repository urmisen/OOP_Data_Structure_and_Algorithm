#include<bits/stdc++.h>
using namespace std;

int main(){
    int w;
    for(int i=1;i<=100;i++){
        cin>>w;
        if(w%2==0 && w!=2){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }

    return 0;
}
