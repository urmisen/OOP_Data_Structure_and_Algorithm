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
          if(i%3==0)
          {
            integration = integration + 2 * (f(x));
          }
          else
          {
            integration = integration + 3 * (f(x));
          }

         }
      integration = integration * h*3.0/8.0;
      cout<< endl <<"Simpson's 3/8 rule gives, integration = "<< integration;
     }
 return 0;
}
