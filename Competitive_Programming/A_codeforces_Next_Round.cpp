#include<bits/stdc++.h>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;




int main(){
    int n,k;
    int arr[100];
    int count = 0;

    cin>>n>>k;

    for(int i=1; i<=n;i++){
        cin>>arr[i];
    }

    for(int j=1; j<=n; j++){

        if(arr[j] > 0 && arr[j]>=arr[k]){

            count++;
        }
    }

    cout<<count;

    return 0;

}
