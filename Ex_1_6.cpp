#include<iostream>
#include<iomanip>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

float Relative_Error(float a,float b){
     return a/b;
     }

int main(){
    float x,y,z,S,E_A,E_R;
    cout<< setprecision(3)<<fixed;
    x = sqrt(3);
    y = sqrt(5);
    z = sqrt(7);

    S = x + y + z;
    cout<<"S : "<<S<<endl;
    cout<< setprecision(4)<<fixed;
    E_A= (1.0/2)*((1.0/1000) + (1.0/1000) + (1.0/1000));
    E_R = Relative_Error(E_A,S);

    cout<< "Absolute Error : "<<E_A<<endl;
    cout<< "Relative Error : "<<E_R<<endl;


    return 0;
}


