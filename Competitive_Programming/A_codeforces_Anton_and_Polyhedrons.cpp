#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n,count=0;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]=="Tetrahedron"){
            count+=4;
        }
        if(arr[i]=="Cube"){
            count+=6;
        }
        if(arr[i]=="Octahedron"){
            count+=8;
        }
        if(arr[i]=="Dodecahedron"){
            count+=12;
        }
        if(arr[i]=="Icosahedron"){
            count+=20;
        }
    }

    cout<<count;

    return 0;
}




