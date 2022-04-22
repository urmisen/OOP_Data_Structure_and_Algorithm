#include <cmath>
#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double Ln(double n)
{
	double num, mul, cal, sum = 0;
	num = (n - 1) / (n + 1);
	for (int i = 1; i <= 1000; i++) {
		mul = (2 * i) - 1;
		cal = pow(num, mul);
		cal = cal / mul;
		sum = sum + cal;
	}
	sum = 2 * sum;
	return sum;
}
int main()
{
 int n, i;
 cout<<"Enter the number of data points: ";
 cin>>n;
 float x[n], y[n], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;
 cout<< setprecision(4)<< fixed;
 cout<<"Enter data:"<< endl;

 for(i=1;i<=n;i++)
 {
  cout<<"x["<< i <<"] = ";
  cin>>x[i];
  cout<<"y["<< i <<"] = ";
  cin>>y[i];
 }
 for(i=1;i<=n;i++)
 {
  sumX = sumX + x[i];
  sumX2 = sumX2 + x[i]*x[i];
  sumY = sumY + Ln(y[i]);
  sumXY = sumXY + x[i]*Ln(y[i]);
 }
 b = (sumX*sumY - n*sumXY)/(sumX*sumX - n*sumX2);
 a = (sumY - b*sumX)/n;

 double a0=exp(a);
 cout<<"\nValue of a is : "<< a0 <<endl<<"Value of b is "<< b <<endl;
 cout<<"Best straight line fit : y = "<< a0 <<" e^ "<< b<<"x"<<endl;

 return(0);
}
