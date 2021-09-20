#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int x,Par1,Par2,Par3;
    int count = 0;
    cin>>x;
    for(int i=0 ; i<x ; i++)
    {
        cin>>Par1>>Par2>>Par3;
        if(Par1+Par2+Par3 >= 2){
            count++;
        }
    }

    cout<<count<<"\n";

    return 0;
    }
