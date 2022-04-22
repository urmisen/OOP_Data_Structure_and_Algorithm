#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int t,n;
    cin>>t;

    while(t--){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        sort(arr,arr+n);
        bool flag=true;
        for(int k=1;k<n;k++){
            if((arr[k]-arr[k-1])>1){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}




