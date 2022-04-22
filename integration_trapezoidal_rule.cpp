#include<iostream>
#include<iomanip>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

#define f(x) 1/(1+x)

int main()
{
 float lower, upper, integration=0.0, h, x, y,t;
 int i, n;
 /* Input */
 cout<<"Enter the lower limit : ";
 cin>>lower;
 cout<<"Enter the upper limit : ";
 cin>>upper;
 cout<<"Enter the test case for t : ";
 cin>>t;
while(t--){
     cout<<"\nEnter number the value of h: ";
     cin>>h;
     n = (upper - lower)/h;
     cout<<"x"<<"\t"<<"y"<<endl;
     cout<<"-------------------"<<endl;
     for(i=0; i<= n; i++)
     {
      x = lower + i*h;
      y = (f(x));
      cout << x<<"\t" << y<<endl;
     }
      cout<< setprecision(4)<< fixed;
     /* Finding Integration Value */
     integration = f(lower) + f(upper);
     for(i=1; i< n; i++)
     {
      x = lower + i*h;
      integration = integration + 2 * (f(x));
     }
     integration = integration * h/2;
     cout<< setprecision(4)<<"\nTrapezoidal rule gives,
      integration = "<< integration<<endl;
     }
 return 0;
}
