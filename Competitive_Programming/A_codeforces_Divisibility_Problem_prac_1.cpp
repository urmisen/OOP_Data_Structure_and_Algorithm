#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int t;
    long long int a,b;
    int count=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a%b==0){

            cout<<count;
        }
        else{

            do {
              ++count;
              a++;

            }
            while (a%b!=0);
            cout<<count;
            cout<<endl;
            count=0;
        }
    }


    return 0;
}


