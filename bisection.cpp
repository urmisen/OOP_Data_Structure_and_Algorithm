
#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

double func(double x)
{
    return x*x*x-2*x-5;
}

double bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
    }
    if (func(a) * func(b) < 0)
    {
        float x_r=(a+b)/2;
        if(func(a) * func(x_r) < 0){
            b=x_r;
            float x_r=(a+b)/2;
        }
        if(func(a) * func(x_r) > 0){
            a=x_r;
            float x_r=(a+b)/2;
        }

        return x_r;
    }


}
int main()
{

    double a =2, b = 3;
    bisection(a, b);
    return 0;
}
