#include<bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;


int main(){
    int N,i,j,temp;
    cin>>N;
    int A[N];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    for(i=0,j=N-1;i<N/2;i++,j--){
        temp=A[j];
        A[j]=A[i];
        A[i]=temp;
    }

    for(int i=0;i<N;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}
