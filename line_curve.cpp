#include<iostream>
using namespace std;

int main()
{
 int n, i;

 cout<<"Enter the number of data points: ";
 cin>>n;
 float x[n], y[n], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;

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
  sumY = sumY + y[i];
  sumXY = sumXY + x[i]*y[i];
 }

 b = (sumX*sumY - n*sumXY)/(sumX*sumX - n*sumX2);
 a = (sumY - b*sumX)/n;


 cout<<"\nValue of a is : "<< a <<endl<<"Value of b is "<< b <<endl;
 cout<<"Best straight line fit : y = "<< a <<" + "<< b<<"x"<<endl;

 return(0);
}
