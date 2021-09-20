#include<bits/stdc++.h>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;




int main(){

    int n;
    int x=0;
    string stat;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stat;
        if(stat[1]== '+'){
            x++;
        }
        else{
            x--;
        }

    }
    cout<<x;

    return 0;

}
