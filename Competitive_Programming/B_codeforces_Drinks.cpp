#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    float sum=0,output;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];
        }
    output=sum/n;
    cout<<output;
    return 0;

}


