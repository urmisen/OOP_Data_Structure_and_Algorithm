#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int desc,a,b,c;
    int x[4];
    for(int i=0;i<4;i++){
        cin>>x[i];
    }

    for (int i=0;i<4;++i)
    {
        for (int j=i+1;j<4;++j)
        {
            if (x[i] < x[j])
            {
                desc = x[i];
                x[i] = x[j];
                x[j] = desc;
            }
        }
    }

    for (int i=0; i<4;++i)
    {
        a=x[0]-x[3];
        b=x[1]-a;
        c=x[0]-(a+b);
    }
    cout<<a<<" "<<b<<" "<<c;

   return 0;
}

