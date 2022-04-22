#include<iostream>
#include<iomanip>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

double Absolute_Error(float a,float b){
     return (a-b);
     }

int main(){
    float x,diff,abs,val;

    cout<< setprecision(2)<< fixed;
    x = 1.0/3;

    float arr[]={0.30,0.33,0.34};
    diff=x-arr[0];
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<arrSize;i++){
        if(x>=arr[i]){
            abs= x-arr[i];
        }
        else{
            abs= arr[i]-x;
        }
        if(abs<diff){
            diff=abs;
            val=arr[i];
        }
    }

    cout<<"Best approximation for 1/3 is : "<<val<<endl;

    return 0;
}






