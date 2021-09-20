#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){

    int i,j,x[5][5];
    int moves=0;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin>>x[i][j];
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(x[i][j]==1){
                moves=abs(i-2)+ abs(j-2);
            }
        }
    }

    cout<<moves;
    return 0;
}
