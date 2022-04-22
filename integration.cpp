#include<iostream>
#include<iomanip>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

#define f(x) 1/(1+x)

float trapezoidal(float lower, float upper,float h,float n){

    float integration=0.0,x;
    integration = f(lower) + f(upper);

    for(int i=1; i< n; i++)
     {
      x = lower + i*h;
      integration = integration + 2 * (f(x));
     }
    integration = integration * h/2;
    cout<<setprecision(4)<<"\nTrapezoidal rule gives, integration = "<< integration;
    return integration;
}

float Simpson_1_3(float lower, float upper,float h,float n){

    float integration=0.0,x;
    integration = f(lower) + f(upper);
    for(int i=1; i< n; i++)
        {
        x = lower + i*h;
        if(i%2==0)
        {
            integration = integration + 2 * (f(x));
        }
        else
          {
            integration = integration + 4 * (f(x));
        }
    }
    integration = integration * h/3;
    cout<< endl <<"Simpson's 1/3 rule gives, integration =  "<< integration;
    return integration;
}

float Simpson_3_8(float lower, float upper,float h,float n){

     float integration=0.0,x;
     integration = f(lower) + f(upper);
     for(int i=1; i< n; i++)
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
     cout<< endl <<"Simpson's 3/8 rule gives, integration = "<< integration<<endl;
     return integration;
}


int main()
{
 float lower, upper, h, x, y, sum1,sum2,sum3,acc_value= 0.6931;
 int i, n, t;

 /* Input */
 cout<<"Enter the lower limit : ";
 cin>>lower;
 cout<<"Enter the upper limit : ";
 cin>>upper;
     cout<<"\nEnter number the value of h: ";
     cin>>h;
     cout<< setprecision(4)<< fixed;
     n = (upper - lower)/h;
     cout<<"x"<<"\t"<<"y"<<endl;
     cout<<"-------------------"<<endl;
     for(i=0; i<= n; i++)
     {
      x = lower + i*h;
      y = (f(x));
      cout << x<<"\t" << y<<endl;
     }
     cout<<"Actual value of Integration = " <<acc_value<<endl;
     sum1=trapezoidal(lower,upper,h,n);
     sum2=Simpson_1_3(lower,upper,h,n);
     sum3=Simpson_3_8(lower,upper,h,n);

     cout<<"\nTrapezoidal rule gives, Error Rate = "<< fabs((acc_value-sum1));
     cout<<"\nSimpson's 1/3 rule gives, Error Rate =  "<< fabs((acc_value-sum2));
     cout<<"\nSimpson's 1/3 rule gives, Error Rate =  "<< fabs((acc_value-sum3))<<endl;

     if(fabs((acc_value-sum1)) < fabs((acc_value-sum2)) && fabs((acc_value-sum1))
         < fabs((acc_value-sum3))){
        cout<<"\nFor This example, Trapezoidal Rule Performed Better Than Simpson's
            1/3 and 3/8 Rule."<<endl;
     }
     if(fabs((acc_value-sum2)) < fabs((acc_value-sum1)) && fabs((acc_value-sum2))
         < fabs((acc_value-sum3))){
        cout<<"\nFor This example, Simpson's 1/3 Performed Better Than Trapezoidal
        Rule and Simpson's 3/8 Rule."<<endl;
     }
     if(fabs((acc_value-sum3)) < fabs((acc_value-sum1)) && fabs((acc_value-sum3))
        < fabs((acc_value-sum2))){
        cout<<"\nFor This example, Simpson's 3/8 Performed Better Than Trapezoidal
        Rule and Simpson's 1/3 Rule."<<endl;
     }
 return 0;
}
