#include<bits/stdc++.h>
#include <iostream>
using namespace std;

float Absolute_Error(float a,float b){
     return (a-b);
     }

float Relative_Error(float a,float b){
     return (a-b)/a;
     }

int main(){
    float x1, x;
    float E_A,E_R;
    x=  3.1415926;
    x1 = 22.0/7;


    cout<< setprecision(7)<< fixed;
    E_A = Absolute_Error(x,x1);
    E_R = Relative_Error(x,x1);


    cout<<"Absolute Error : "<<E_A<<endl;
    cout<<"Relative Error : "<<E_R<<endl;;

    return 0;
}


